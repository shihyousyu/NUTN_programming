const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');
const root = path.resolve(__dirname, '..');
function files(folder){
    return fs.readdirSync(folder, {withFileTypes:true}).flatMap(item =>
        item.isDirectory() ? files(path.join(folder, item.name)) : [path.join(folder, item.name)]);
}
function scripts(file){
    const text = fs.readFileSync(path.join(root, file), 'utf8');
    return file.endsWith('.js') ? [text] : [...text.matchAll(/<script(?:\s[^>]*)?>([\s\S]*?)<\/script>/gi)].map(match => match[1]);
}
// These are DOM-independent behavior tests, not browser layout/autoplay tests.
for(const file of files(path.join(root, '2-2')).filter(file => /\.(html|js)$/.test(file))){
    for(const script of scripts(path.relative(root, file))) new vm.Script(script);
}
class Element{
    constructor(){this.value='';this.textContent='';this.innerHTML='';this.children=[];this.style={};this.events={};}
    appendChild(child){this.children.push(child);}
    replaceChildren(...children){this.children=children;}
    setAttribute(name,value){this[name]=value;}
    addEventListener(name,fn){this.events[name]=fn;}
}
function storage(){
    const map = new Map();
    return {getItem:key=>map.get(key)??null, setItem:(key,value)=>map.set(key,String(value)),
        key:index=>[...map.keys()][index],removeItem:key=>map.delete(key),clear:()=>map.clear(),get length(){return map.size;}};
}
function context(file, shared=storage(), prompts=[]){
    const nodes={}, events={}, timers=new Map(), allTimers=[];
    let writes='',timerId=0;
    const document={body:{},getElementById(id){return nodes[id]??=(new Element());},createElement(){return new Element();},write(s){writes+=s;},writeln(s){writes+=s+'\n';}};
    const window={addEventListener(event,fn){events[event]=fn;},prompt(){return prompts.length ? prompts.shift() : null;},alert(){}};
    const sandbox=vm.createContext({document,window,localStorage:shared,sessionStorage:storage(),console,
        Audio:class{play(){return Promise.resolve();}},
        setTimeout(fn){allTimers.push(fn);timers.set(++timerId,fn);return timerId;},
        clearTimeout(id){timers.delete(id);}});
    for(const script of scripts(file)) vm.runInContext(script,sandbox);
    return {sandbox,nodes,events,timers,allTimers,document,window,get writes(){return writes;}};
}
let c=context('2-2/20260421/excercise2.html');
c.document.getElementById('ans').value='123';
vm.runInContext("pushBtn('DEL')",c.sandbox);assert.equal(c.nodes.ans.value,'12');
vm.runInContext("pushBtn('C')",c.sandbox);assert.equal(c.nodes.ans.value,'0');
for(const [expression,answer] of [['2+3*4',14],['(2+3)*4',20],['-2+3',1],['5%2',1],['.5+1.25',1.75]]){
    assert.equal(vm.runInContext(`evaluateExpression(${JSON.stringify(expression)})`,c.sandbox),answer);
}
for(const bad of ['1/0','1+','alert(1)','1..2']) assert.throws(()=>vm.runInContext(`evaluateExpression(${JSON.stringify(bad)})`,c.sandbox));
c=context('2-2/20260414/excercise1.html',storage(),['-1']);assert.match(c.writes,/No numbers/);assert.doesNotMatch(c.writes,/NaN|Infinity/);
c=context('2-2/20260414/excercise1.html',storage(),['2','4','6','-1']);assert.match(c.writes,/avg is 4/);
c=context('2-2/20260414/excercise1.html',storage(),[null]);assert.match(c.writes,/No numbers/);
c=context('2-2/20260519/excercise1.html');c.events.load();
const cards=[...c.nodes.shuffleTable.innerHTML.matchAll(/pokers\/(\d+)\.png/g)].map(match=>Number(match[1]));assert.equal(cards.length,52);assert.equal(new Set(cards).size,52);
c=context('2-2/20260519/excercise2.html');c.events.load();
vm.runInContext('deck[1]=deck[0];flip(0);flip(1)',c.sandbox);
const stale=c.allTimers[0];c.nodes.restart.events.click();vm.runInContext('flip(2)',c.sandbox);stale();
assert.equal(vm.runInContext('revealed[2]',c.sandbox),false);assert.equal(vm.runInContext('firstPick',c.sandbox),2);assert.equal(vm.runInContext('revealed[-1]',c.sandbox),undefined);assert.equal(c.timers.size,0);
const shared=storage();shared.setItem('other-app','keep');shared.setItem('nutn:grades:bad','null');
c=context('2-2/20260526/exercise2/FavoriteTwitterSearches.js',shared);c.events.load();
c.document.getElementById('tag').value="<b>quoted'</b>";c.document.getElementById('query').value='a&b #c';vm.runInContext('saveSearch()',c.sandbox);
const list=c.nodes.searches.children[0];assert.equal(list.children.length,1);const link=list.children[0].children[0].children[0];assert.equal(link.textContent,"<b>quoted'</b>");assert.match(link.href,/a%26b%20%23c/);
let grades=context('2-2/20260526/exercise3/FavoriteTwitterSearches.js',shared);grades.events.load();
assert.equal(grades.nodes.searches.children[0].children.length,1); // Header only; invalid record ignored.
grades.document.getElementById('tag').value='student1';for(const [key,value] of [['physics','60'],['calculus','75'],['discrete','90']])grades.document.getElementById(key).value=value;
vm.runInContext('saveSearch()',grades.sandbox);assert.equal(JSON.parse(shared.getItem('nutn:grades:student1')).physics,60);
assert.equal(grades.nodes.searches.children[0].children[1].children[4].textContent,'75.00');
vm.runInContext('clearAllSearches()',c.sandbox);assert.ok(shared.getItem('nutn:grades:student1'));assert.equal(shared.getItem('other-app'),'keep');
vm.runInContext('clearAllSearches()',grades.sandbox);assert.equal(shared.getItem('other-app'),'keep');
console.log('JavaScript syntax, calculator, statistics, shuffle, timer and storage regressions passed.');
