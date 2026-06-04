// Fig. 11.7: SearchingStrings.js 
// Searching strings with indexOf and lastIndexOf.
var letters = "abcdefghijklmnopqrstuvwxyzabcdefghijklm";

function buttonPressed() 
{
   var inputField = document.getElementById( "inputField" );
   var searchKey = inputField.value;
   var count = 0;

   var position = letters.indexOf(searchKey);

   if (searchKey.length > 0) {
      while (position !== -1) {
         count++;
         position = letters.indexOf(searchKey, position + 1);
      }
   }

   document.getElementById( "results" ).innerHTML =
      "<p>First occurrence is located at index " + 
         letters.indexOf( searchKey ) + "</p>" +  
      "<p>Last occurrence is located at index " + 
         letters.lastIndexOf( searchKey ) + "</p>" +      
      "<p>First occurrence from index 12 is located at index " +
         letters.indexOf( searchKey, 12 ) + "</p>" +     
      "<p>Last occurrence from index 12 is located at index " +
         letters.lastIndexOf( searchKey, 12 ) + "</p>" +
      "<p>The number of occurrences of substring is " + count + "</p>";
} // end function buttonPressed

// register click event handler for searchButton
function start()
{
   var searchButton = document.getElementById( "searchButton" );
   searchButton.addEventListener( "click", buttonPressed, false );
} // end function start

window.addEventListener( "load", start, false );


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