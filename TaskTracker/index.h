const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
<style>
/* Remove margins and padding from the list */
ul {
  margin: 0;
  padding: 0;
}

/* Style the list items */
ul li {
  cursor: pointer;
  position: relative;
  padding: 12px 8px 12px 40px;
  list-style-type: none;
  background: #eee;
  font-family:'Arial';
  font-size: 22px;
  transition: 0.2s;
  height: 110px;

  /* make the list items unselectable */
  -webkit-user-select: none;
  -moz-user-select: none;
  -ms-user-select: none;
  user-select: none;
}

/* Set all odd list items to a different color (zebra-stripes) */
ul li:nth-child(odd) {
  background: #f9f9f9;
}

/* Darker background-color on hover */
ul li:hover {
  background: #ddd;
}

/* When clicked on, add a background color and strike out text */
ul li.checked {
  background: #09a009;
  color: #fff;
  text-decoration: line-through;
}

.points {
  position: absolute;
  left: 24px;
  top: 60px;
  padding: 12px 16px 12px 16px;
  font-size: 16px;
}

.timer {
  position: absolute;
  left: 24px;
  top: 35px;
  padding: 12px 16px 12px 16px;
  font-size: 16px;
}

/* Style the close button */
.close {
  position: absolute;
  right: 0;
  top: 28px;
  padding: 12px 16px 12px 16px;
}

.close:hover {
  background-color: #D22F30;
  color: white;
}

/* Style the header */
.header {
  margin: 0;
  background-color: #D22F30;
  padding: 30px 10px;
  color: white;
  text-align: center;
  font-size: 48px;
  font-family: Arial;
  text-decoration-line: underline;
}

/* Style the input box */
.inputBox {
  display: inline-block;
  border: none;
  padding-left: 12px;
  width: 70%;
  font-family:'Arial';
  font-size: 36px;
  vertical-align: center;
}

/* Style the "Add" button */
.addBtn {
  width: 20%;
  height: 56px;
  background: #09a009;
  color: #ffffff;
  text-align: center;
  float: right;
  cursor: pointer;
  transition: 0.3s;
  padding: 0px;
  font-family:'Arial';
  font-size: 24px;
}

.streakImageL {
  position: absolute;
  height: 90px;
  right: 69%;
}

.streakImageR {
  position: absolute;
  height: 90px;
  left: 69%;
}

.streakText {
  font-family:'Arial';
  font-weight: 600;
  color: white;
  background-color: #D22F30;
  text-align: center;
  font-size: 63px;
  margin-top: 0px;
  margin-bottom: 0px;
}

.reorder {
  position: absolute;
  top: 40px;
  left: 10px;
  height: 15px;
  /* Prevent scrolling down the page when we want to just reorder the list */
  touch-action: none;
}

</style>
</head>
<body>
<!-- Place the title of the Webpage -->
<h2 class="header">Today's To-Do List</h2>

<!-- Parent div forces all on the same line-->
<div id="parent" style="white-space: nowrap; overflow-x: auto;">
  <!-- Place the streak image -->
  <img src="https://t4.ftcdn.net/jpg/03/63/57/21/360_F_363572186_25fxXDyWgNHeQtyPnb9YP9T6DVv7UP1N.jpg" class="streakImageL">
  <img src="https://t4.ftcdn.net/jpg/03/63/57/21/360_F_363572186_25fxXDyWgNHeQtyPnb9YP9T6DVv7UP1N.jpg" class="streakImageR">
  <!-- Place the number for the streak -->
  <h1 class="streakText">145</h1>
</div>

<!-- Parent div forces all on the same line-->
<div id="parent" style="white-space: nowrap; overflow-x: auto;">
  <!-- Place the add button to add the element to the list -->
  <button onclick="newElement()" class="addBtn">Add</button>
  <!-- Place the input box for entering a new task -->
  <input class="inputBox" type="text" id="myInput" placeholder="Enter a New Task...">
</div>

<!-- Show the list elements -->

<ul id="list">
  <li draggable="true">List Item 1</li>
  <li draggable="true">List Item 2</li>
  <li draggable="true">List Item 3</li>
  <li draggable="true">List Item 4</li>
  <li draggable="true">List Item 5</li>
  <li draggable="true">List Item 6</li>
  <li draggable="true">List Item 7</li>
  <li draggable="true">List Item 8</li>
  <li draggable="true">List Item 9</li>
  <li draggable="true">List Item 10</li>
  <li draggable="true">List Item 11</li>
  <li draggable="true">List Item 12</li>
  <li draggable="true">List Item 13</li>
  <li draggable="true">List Item 14</li>
  <li draggable="true">List Item 15</li>
  <li draggable="true">List Item 16</li>
  <li draggable="true">List Item 17</li>
  <li draggable="true">List Item 18</li>
  <li draggable="true">List Item 19</li>
  <li draggable="true">List Item 20</li>
  <li draggable="true">List Item 21</li>
  <li draggable="true">List Item 22</li>
  <li draggable="true">List Item 23</li>
  <li draggable="true">List Item 24</li>
  <li draggable="true">List Item 25</li>
  <li draggable="true">List Item 26</li>
</ul>

<script>
var dragging = null;

var lastTouchX, lastTouchY;

document.addEventListener('touchmove', function(event) {
    var target = getLI(event.target);
    dragging = target;
    lastTouchX = event.touches[0].clientX;
    lastTouchY = event.touches[0].clientY;
    var actualTarget = getLI(document.elementFromPoint(lastTouchX, lastTouchY));
    var bounding = actualTarget.getBoundingClientRect()
    var offset = bounding.y + (bounding.height / 2);

    var list = document.getElementsByTagName("LI");
    var i;
    // Remove borders on the other lines where we are not currently dragging to
    for (i = 0; i < list.length; i++)
    {
        list[i].style['border-bottom'] = '';
        list[i].style['border-top'] = '';
    }

    if (event.clientY - offset > 0) {
         actualTarget.style['border-bottom'] = 'solid 2px black';
        actualTarget.style['border-top'] = '';
    } else {
        actualTarget.style['border-top'] = 'solid 2px black';
        actualTarget.style['border-bottom'] = '';
    }
});

document.addEventListener('touchend', function(event) {
    var target = getLI(event.target);
    var actualTarget = getLI(document.elementFromPoint(lastTouchX, lastTouchY));
    target.parentNode.insertBefore(dragging, actualTarget);
    actualTarget.style['border-bottom'] = '';
    actualTarget.style['border-top'] = '';
});

document.addEventListener('dragstart', function(event) {
    var target = getLI(event.target);
    dragging = target;
    event.dataTransfer.setData('text/plain', null);
    event.dataTransfer.setDragImage(self.dragging, 0, 0);
});

document.addEventListener('dragover', function(event) {
    event.preventDefault();
    var target = getLI(event.target);
    var bounding = target.getBoundingClientRect()
    var offset = bounding.y + (bounding.height / 2);
    if (event.clientY - offset > 0) {
        target.style['border-bottom'] = 'solid 2px black';
        target.style['border-top'] = '';
    } else {
        target.style['border-top'] = 'solid 2px black';
        target.style['border-bottom'] = '';
    }
}); 

document.addEventListener('dragleave', function(event) {
    var target = getLI(event.target);
    target.style['border-bottom'] = '';
    target.style['border-top'] = '';
});

document.addEventListener('drop', function(event) {
    event.preventDefault();
    var target = getLI(event.target);
    if (target.style['border-bottom'] !== '') {
        target.style['border-bottom'] = '';
        target.parentNode.insertBefore(dragging, event.target.nextSibling);
    } else {
        target.style['border-top'] = '';
        target.parentNode.insertBefore(dragging, event.target);
    }
});

function sendData(argument, dataTag, data) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      // Don't worry about this.
    }
  };
  var str = argument + "?";
  for (var i = 0; i < dataTag.length; i++)
  {
    str += dataTag[i] + "=" + data[i];
  }
  console.log(dataTag.length);
  console.log(str);
  xhttp.open("GET", str, true); // true for asynchronous
  xhttp.send();
}

function getLI(target) {
    while (target.nodeName.toLowerCase() != 'li' && target.nodeName.toLowerCase() != 'body') {
        target = target.parentNode;
    }
    if (target.nodeName.toLowerCase() == 'body') {
        return false;
    } else {
        return target;
    }
}

// Create a "close" button and append it to each list item
var myNodelist = document.getElementsByTagName("LI");
var i;
for (i = 0; i < myNodelist.length; i++) {
  var span = document.createElement("SPAN");
  var txt = document.createTextNode("\u00D7");
  span.className = "close";
  span.appendChild(txt);
  myNodelist[i].appendChild(span);
}

// create points text
var myNodelist = document.getElementsByTagName("LI");
var i;
for (i = 0; i < myNodelist.length; i++) {
  var span = document.createElement("SPAN");
  var txt = document.createTextNode("+999");
  span.className = "points";
  span.appendChild(txt);
  myNodelist[i].appendChild(span);
}

// create timer text
var myNodelist = document.getElementsByTagName("LI");
var i;
for (i = 0; i < myNodelist.length; i++) {
  var span = document.createElement("SPAN");
  var txt = document.createTextNode("+03:57:49");
  span.className = "timer";
  span.appendChild(txt);
  myNodelist[i].appendChild(span);
}

// Click on a close button to hide the current list item
var close = document.getElementsByClassName("close");
var i;
for (i = 0; i < close.length; i++) {
  close[i].onclick = function() {
    var div = this.parentElement;
    div.parentNode.removeChild(div);
  }
}

// Add a "checked" symbol when clicking on a list item
var list = document.querySelector('ul');
list.addEventListener('click', function(ev) {
  if (ev.target.tagName === 'LI') {
    ev.target.classList.toggle('checked');
  }
}, false);

// Create a new list item when clicking on the "Add" button
function newElement() {
  var li = document.createElement("li");
  li.draggable = true;
  var inputValue = document.getElementById("myInput").value;
  var t = document.createTextNode(inputValue);
  li.appendChild(t);
  if (inputValue === '') {
    /* alert("You must write something!"); */
  } else {
    document.getElementById("list").appendChild(li);
  }
  document.getElementById("myInput").value = "";

  // create the X
  var span = document.createElement("SPAN");
  var txt = document.createTextNode("\u00D7");
  span.className = "close";
  span.appendChild(txt);
  li.appendChild(span);

  // create the timer
  var timer = document.createElement("SPAN");
  var txt = document.createTextNode("+03:57:49");
  timer.className = "timer";
  timer.appendChild(txt);
  li.appendChild(timer);

  // create points
  var points = document.createElement("SPAN");
  var txt = document.createTextNode("+999");
  points.className = "points";
  points.appendChild(txt);
  li.appendChild(points);

  for (i = 0; i < close.length; i++) {
    close[i].onclick = function() {
      var div = this.parentElement;
      div.parentNode.removeChild(div);
    }
  }

  // send GET request to server to add it to the physical list
  var dataTag = [ "itemName" ];
  var data    = [ inputValue ];
  
  sendData("addNewItem", dataTag, data);
}
</script>
</body>
</html>
)=====";