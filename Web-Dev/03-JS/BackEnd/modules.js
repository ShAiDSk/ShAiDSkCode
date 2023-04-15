// import { readFileSync } from "fs";
const fs = require("fs");
const { test } = require("node:test");
let text = fs.readFileSync("read.txt", "utf-8");
text = text.replace("Shaid sk", "Leo Lua");
console.log(text);
fs.writeFileSync("lua.txt", text);