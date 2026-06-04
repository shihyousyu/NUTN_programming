var tags; 

function saveSearch() 
{
   var id = document.getElementById("tag").value;
   var p = document.getElementById("physics").value;
   var c = document.getElementById("calculus").value;
   var d = document.getElementById("discrete").value;

   var grades = {
      physics: p,
      calculus: c,
      discrete: d
   };

   localStorage.setItem(id, JSON.stringify(grades)); 

   document.getElementById("tag").value = "";
   document.getElementById("physics").value = "";
   document.getElementById("calculus").value = "";
   document.getElementById("discrete").value = "";
   
   loadSearches(); 
}

function loadSearches() 
{
   var length = localStorage.length; 
   tags = []; 

   for (var i = 0; i < length; ++i) {
      tags[i] = localStorage.key(i);
   } 
   tags.sort(); 

   var markup = "<table border='1' width='100%'>" +
                "<thead><tr><th>Student Id</th><th>Physics</th><th>Calculus</th>" +
                "<th>Discrete Math</th><th>Average</th><th>Action</th></tr></thead><tbody>";

   for (var tag in tags) 
   {
      var storageItem = localStorage.getItem(tags[tag]);
      var data;
      
      try {
          data = JSON.parse(storageItem);
      } catch(e) {
          continue; 
      }
      
      var p = parseFloat(data.physics) || 0;
      var c = parseFloat(data.calculus) || 0;
      var d = parseFloat(data.discrete) || 0;
      var avg = ((p + c + d) / 3).toFixed(2);

      markup += "<tr>" +
         "<td>" + tags[tag] + "</td>" +
         "<td>" + data.physics + "</td>" +
         "<td>" + data.calculus + "</td>" +
         "<td>" + data.discrete + "</td>" +
         "<td>" + avg + "</td>" +
         "<td><input type='button' value='Delete' onclick='deleteTag(\"" + tags[tag] + "\")'></td>" +
         "</tr>";
   } 

   markup += "</tbody></table>";
   document.getElementById("searches").innerHTML = markup;
}

function deleteTag( tag ) 
{
   localStorage.removeItem( tag );
   loadSearches(); 
}

function clearAllSearches() 
{
   localStorage.clear();
   loadSearches(); 
}

function start()
{
   var saveButton = document.getElementById( "saveButton" );
   saveButton.addEventListener( "click", saveSearch, false );
   
   var clearButton = document.getElementById( "clearButton" );
   clearButton.addEventListener( "click", clearAllSearches, false );
   
   loadSearches(); 
}

window.addEventListener( "load", start, false );