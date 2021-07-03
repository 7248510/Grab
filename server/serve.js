//https://www.digitalocean.com/community/tutorials/use-expressjs-to-deliver-html-files
//npm init
//npm install express --save-prod
//npm install serve-index --save-prod This is a module of ExpressJS
//The dependencies are added to package.json
const express = require('express'); //Requiring the module express
const app = express();
const port = 3000; //port 3000
const hostname = '0.0.0.0'; //Serve on all local IP's
const path = require('path'); //Core nodejs component
var serveIndex = require('serve-index');
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'index.html')); //__dirname is a predefined variable
});
//Begin serving static files & serving directories
app.use('/cyber', express.static('cyber'), serveIndex('cyber'));
app.use('/development', express.static('development'), serveIndex('development'));
app.use('/internet', express.static('internet'), serveIndex('internet'));
app.use('/all', express.static('all'), serveIndex('all'));
//NAME, FOLDER, FOLDERTOSERVE
//(directory that the user requests), 'folder name'
//app.listen(port, hostname, () => {
app.listen(port, hostname, () => {
    console.log("Serving Initial's directorys!");
    console.log(`Cyber: ${hostname}:${port}/cyber`);
    console.log(`Development: ${hostname}:${port}/development`);
    console.log(`Internet: ${hostname}:${port}/internet`);
    console.log(`all: ${hostname}:${port}/all`);
});