const GRADE_PREFIX = "nutn:grades:";
const SUBJECTS = ["physics", "calculus", "discrete"];

function validGrades(data){
    return data !== null && typeof data === "object" && !Array.isArray(data) &&
        SUBJECTS.every(subject => typeof data[subject] === "number" &&
            Number.isFinite(data[subject]) && data[subject] >= 0 && data[subject] <= 100);
}
function saveSearch(){
    const id = document.getElementById("tag").value.trim();
    const grades = {};
    for(const subject of SUBJECTS){
        const value = document.getElementById(subject).value.trim();
        if(value === ""){window.alert("Enter all three grades."); return;}
        grades[subject] = Number(value);
    }
    if(!id || !validGrades(grades)){window.alert("Enter a student ID and grades between 0 and 100."); return;}
    localStorage.setItem(GRADE_PREFIX + id, JSON.stringify(grades));
    document.getElementById("tag").value = "";
    for(const subject of SUBJECTS) document.getElementById(subject).value = "";
    loadSearches();
}
function loadSearches(){
    const table = document.createElement("table");
    table.setAttribute("border", "1");
    table.style.width = "100%";
    const header = document.createElement("tr");
    for(const text of ["Student Id", "Physics", "Calculus", "Discrete Math", "Average", "Action"]){
        const cell = document.createElement("th"); cell.textContent = text; header.appendChild(cell);
    }
    table.appendChild(header);
    const keys = [];
    for(let i = 0; i < localStorage.length; ++i){
        const key = localStorage.key(i);
        if(key.startsWith(GRADE_PREFIX)) keys.push(key);
    }
    keys.sort();
    for(const key of keys){
        let data;
        try{data = JSON.parse(localStorage.getItem(key));}catch(error){continue;}
        if(!validGrades(data)) continue;
        const id = key.slice(GRADE_PREFIX.length), row = document.createElement("tr");
        const average = (data.physics + data.calculus + data.discrete) / 3;
        for(const value of [id, data.physics, data.calculus, data.discrete, average.toFixed(2)]){
            const cell = document.createElement("td"); cell.textContent = String(value); row.appendChild(cell);
        }
        const cell = document.createElement("td"), button = document.createElement("input");
        button.type = "button"; button.value = "Delete";
        button.addEventListener("click", () => deleteTag(id));
        cell.appendChild(button); row.appendChild(cell); table.appendChild(row);
    }
    document.getElementById("searches").replaceChildren(table);
}
function deleteTag(id){localStorage.removeItem(GRADE_PREFIX + id); loadSearches();}
function clearAllSearches(){
    const keys = [];
    for(let i = 0; i < localStorage.length; ++i){
        const key = localStorage.key(i);
        if(key.startsWith(GRADE_PREFIX)) keys.push(key);
    }
    for(const key of keys) localStorage.removeItem(key);
    loadSearches();
}
function start(){
    document.getElementById("saveButton").addEventListener("click", saveSearch);
    document.getElementById("clearButton").addEventListener("click", clearAllSearches);
    loadSearches();
}
window.addEventListener("load", start);
