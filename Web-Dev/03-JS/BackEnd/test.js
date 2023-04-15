// console.log("Hello, Shaid!");


const http = require('http');

const hostname = '127.0.0.1';
const port = 3000;

const server = http.createServer((req, res) => {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text');
//   res.end("Hello, I'm Shaid!");
  res.end(`lua.txt`);
    // res.sendFile('lua.txt');
    //assuming app is express Object.
    // app.get('/',function(req,res) {
    //     res.sendFile('lua.txt');
    // });
});

server.listen(port, hostname, () => {
  console.log(`Server running at http://${hostname}:${port}/`);
});