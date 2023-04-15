/*
Synchronous or Blocking
    : line by line execution
Asynchronous or Non-Blocking
    : line by line execution not guaranteed
    : Call back will Fire.
*/
const fs = require('fs');
fs.readFile("lua.txt", "utf-8", (err, data) => {
    console.log(err, data);
});
console.log("lua.txt massage");