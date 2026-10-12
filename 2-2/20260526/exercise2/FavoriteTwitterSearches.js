const SEARCH_PREFIX = "nutn:search:";

function loadSearches(){
    if(!sessionStorage.getItem("nutn:search:visited")){
        sessionStorage.setItem("nutn:search:visited", "true");
        document.getElementById("welcomeMessage").textContent = "Welcome to the Favorite Twitter Searches App";
    }
    const list = document.createElement("ul");
    const keys = [];
    for(let i = 0; i < localStorage.length; ++i){
        const key = localStorage.key(i);
        if(key.startsWith(SEARCH_PREFIX)) keys.push(key);
    }
    keys.sort();
    for(const key of keys){
        const tag = key.slice(SEARCH_PREFIX.length);
        const item = document.createElement("li");
        const span = document.createElement("span");
        const link = document.createElement("a");
        link.href = "https://www.threads.net/search?q=" + encodeURIComponent(localStorage.getItem(key));
        link.textContent = tag;
        span.appendChild(link);
        item.appendChild(span);
        for(const action of ["Edit", "Delete"]){
            const button = document.createElement("input");
            button.type = "button";
            button.value = action;
            button.addEventListener("click", () => action === "Edit" ? editTag(tag) : deleteTag(tag));
            item.appendChild(button);
        }
        list.appendChild(item);
    }
    document.getElementById("searches").replaceChildren(list);
}
function clearAllSearches(){
    const keys = [];
    for(let i = 0; i < localStorage.length; ++i){
        const key = localStorage.key(i);
        if(key.startsWith(SEARCH_PREFIX)) keys.push(key);
    }
    for(const key of keys) localStorage.removeItem(key);
    loadSearches();
}
function saveSearch(){
    const tag = document.getElementById("tag"), query = document.getElementById("query");
    if(!tag.value.trim()) return;
    localStorage.setItem(SEARCH_PREFIX + tag.value, query.value);
    tag.value = query.value = "";
    loadSearches();
}
function deleteTag(tag){localStorage.removeItem(SEARCH_PREFIX + tag); loadSearches();}
function editTag(tag){
    document.getElementById("tag").value = tag;
    document.getElementById("query").value = localStorage.getItem(SEARCH_PREFIX + tag);
}
function start(){
    document.getElementById("saveButton").addEventListener("click", saveSearch);
    document.getElementById("clearButton").addEventListener("click", clearAllSearches);
    loadSearches();
}
window.addEventListener("load", start);

/*************************************************************************
* (C) Copyright 1992-2012 by Deitel & Associates, Inc. and               *
* Pearson Education, Inc. All Rights Reserved.                           *
*                                                                        *
* DISCLAIMER: The authors and publisher of this book have used their     *
* best efforts in preparing the book. These efforts include the          *
* development, research, and testing of the theories and programs        *
* to determine their effectiveness. The authors and publisher make       *
* no warranty of any kind, expressed or implied, with regard to these    *
* programs or to the documentation contained in these books. The authors *
* and publisher shall not be liable in any event for incidental or       *
* consequential damages in connection with, or arising out of, the       *
* furnishing, performance, or use of these programs.                     *
**************************************************************************/
