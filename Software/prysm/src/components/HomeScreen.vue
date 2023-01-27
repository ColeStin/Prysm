<!-- Name of Artifact: HomeScreen.vue
    Summary: Vue files that is responsible for the display of our Home Screen
    including the title, background, nav bar, buttons, etc.
    Programmer's Name(s): Gage Burmaster, Alexander Wilhelm, Andrew Brown
    Date Code was Created: 9/15/2022 
    Date code was revised: 

       9/15 & 9/19 - Gage Burmaster - Creation of basic HTML format as well as
       styling and creation of JavaScript data functionality.

       9/19 & 20 - Gage Burmaster - Start of elementary front end display
       "Save File" and "New File" buttons created as well as "Save File" able to
       successfully open user's computer files to navigate file needed for upload.

       9/22 - Andrew Brown - Creation of nav bar with Prysm title at top of display.

       9/22 - Alexander Wilhelm - Update to Prysm title to be more UI friendly. Change
       to color scheme of front end, display increased in size, about button created on
       top right corner. Revision to background component to allow room for future GUI.

       9/25 - Andrew Brown - Fixed "info" icon which was not displaying right on run-time.
      Added documentation to describe buttons, title, info icon.

       9/25 - Alexander Wilhelm - Added entire prologue comments above with all dates
       and contributors for Sprint 1, as well as all descriptions of revisions. 
       Added additional documentation on HTML styling and JavaScript components.

       9/28 - Alexander Wilhelm - Added "Add Point" and "Remove Point" buttons
       10/22-23 - Gage - Refactor and Bugfix/curve functionality
       11/14 - Gage - add comments to stuff
       12/4 - Alex - Code Refactoring, creation of open file button
       12/4 - Alex - Editing of open file button
-->

<template>
  <!-- Main body which will contain wave table as well as buttons for user input-->
  <div class="mainbody">
    <BarChart />

    <div class="point-adjustment">

      <!-- Creates a point in the center of the graph-->
      <div class="add-point" @click="addPoint">
        <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-node-plus" viewBox="0 0 16 16">
        <path fill-rule="evenodd" d="M11 4a4 4 0 1 0 0 8 4 4 0 0 0 0-8zM6.025 7.5a5 5 0 1 1 0 1H4A1.5 1.5 0 0 1 2.5 10h-1A1.5 1.5 0 0 1 0 8.5v-1A1.5 1.5 0 0 1 1.5 6h1A1.5 1.5 0 0 1 4 7.5h2.025zM11 5a.5.5 0 0 1 .5.5v2h2a.5.5 0 0 1 0 1h-2v2a.5.5 0 0 1-1 0v-2h-2a.5.5 0 0 1 0-1h2v-2A.5.5 0 0 1 11 5zM1.5 7a.5.5 0 0 0-.5.5v1a.5.5 0 0 0 .5.5h1a.5.5 0 0 0 .5-.5v-1a.5.5 0 0 0-.5-.5h-1z"/>
        </svg>
        Add Point 
      </div>

      <!-- Deletes a selected point-->
      <div class="delete-point" @click="deletePoint" >
        <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-node-minus" viewBox="0 0 16 16">
        <path fill-rule="evenodd" d="M11 4a4 4 0 1 0 0 8 4 4 0 0 0 0-8zM6.025 7.5a5 5 0 1 1 0 1H4A1.5 1.5 0 0 1 2.5 10h-1A1.5 1.5 0 0 1 0 8.5v-1A1.5 1.5 0 0 1 1.5 6h1A1.5 1.5 0 0 1 4 7.5h2.025zM1.5 7a.5.5 0 0 0-.5.5v1a.5.5 0 0 0 .5.5h1a.5.5 0 0 0 .5-.5v-1a.5.5 0 0 0-.5-.5h-1zM8 8a.5.5 0 0 1 .5-.5h5a.5.5 0 0 1 0 1h-5A.5.5 0 0 1 8 8z"/>
        </svg>
        Delete Point
      </div>

      <!-- Seperates New, Open, and Save File from Above Row-->
      <div class = "new-open-save"> 

        <!-- Resets the wavetable to original state-->
        <div class="newFile-button" @click="newFile()">New File
              <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-file-earmark-plus-fill" viewBox="0 0 16 16">
              <path d="M9.293 0H4a2 2 0 0 0-2 2v12a2 2 0 0 0 2 2h8a2 2 0 0 0 2-2V4.707A1 1 0 0 0 13.707 4L10 .293A1 1 0 0 0 9.293 0zM9.5 3.5v-2l3 3h-2a1 1 0 0 1-1-1zM8.5 7v1.5H10a.5.5 0 0 1 0 1H8.5V11a.5.5 0 0 1-1 0V9.5H6a.5.5 0 0 1 0-1h1.5V7a.5.5 0 0 1 1 0z"/>
              </svg>
        </div>

        <!-- Opens an existing .prsm file -->
        <div class="openFile-button">
          <label for="open-input" style="cursor: pointer;">
            Open File

            <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-files" viewBox="0 0 16 16">
            <path d="M13 0H6a2 2 0 0 0-2 2 2 2 0 0 0-2 2v10a2 2 0 0 0 2 2h7a2 2 0 0 0 2-2 2 2 0 0 0 2-2V2a2 2 0 0 0-2-2zm0 13V4a2 2 0 0 0-2-2H5a1 1 0 0 1 1-1h7a1 1 0 0 1 1 1v10a1 1 0 0 1-1 1zM3 4a1 1 0 0 1 1-1h7a1 1 0 0 1 1 1v10a1 1 0 0 1-1 1H4a1 1 0 0 1-1-1V4z"/>
            </svg>

            <input id="open-input" type="file" @change="openFile()" style="display: none;"/>
          </label>
        </div>

        <!-- Saves .prsm file to computer-->
        <div class="saveFile-button" @click="saveFile()">Save File
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-file-earmark-arrow-down-fill" viewBox="0 0 16 16">
          <path d="M9.293 0H4a2 2 0 0 0-2 2v12a2 2 0 0 0 2 2h8a2 2 0 0 0 2-2V4.707A1 1 0 0 0 13.707 4L10 .293A1 1 0 0 0 9.293 0zM9.5 3.5v-2l3 3h-2a1 1 0 0 1-1-1zm-1 4v3.793l1.146-1.147a.5.5 0 0 1 .708.708l-2 2a.5.5 0 0 1-.708 0l-2-2a.5.5 0 0 1 .708-.708L7.5 11.293V7.5a.5.5 0 0 1 1 0z"/>
          </svg>
        </div>

    </div>
  
      

      <div class="slidecontainer">
        <a>X: {{(rangeXval  / ratioToDecimal).toFixed(2)}}</a> <!-- For adjusting the x value of a selected point-->
        <input type="range"  min="0" :max="maxWidth" v-model="rangeXval" class="slider" step=".5" :disabled="!pointIsSelected || (selectedPoint&&selectedPoint.config.index == 0) || (selectedPoint&&stage&&selectedPoint.config.index == 1)" id="myRange">
        <a>Y: {{( 1 - (rangeYval / ratioToDecimal) ).toFixed(2)}}</a> <!-- For adjusting the y value of a selected point-->
        <input type="range" min="0"  :max="maxHeight" v-model="rangeYval" class="slider" step=".5" :disabled="!pointIsSelected" id="myRange2">
        <a>Curve: {{rangeCurve}}</a> <!-- For adjusting the curvature of a selected line-->
        <input type="range" min="-1" max="1" step=".1" v-model="rangeCurve" class="slider" id="myRange" :disabled="!lineIsSelected">
      </div>

    </div>
  </div>
  <!-- Bottom section of file containing save and new file buttons-->
  <div class="background">
    <!-- <div class="saveFile-button" @click="saveFile()">Save File</div>
    <div class="newFile-button" @click="newFile()">New File</div> -->
  </div>
</template>
  
<script>
import BarChart from './chart.vue'

export default {
  data: function () {
    return { //think of the return section as the private member vars of a class (this component). They can be accessed with this.whatever (unless you've changed what this is)
      //range values
      rangeXval: 0.0,
      rangeYval: 0.0,
      rangeCurve: 0.0,
      selectedPoint: null,
      pointIsSelected: false,
      lineIsSelected: false,
      selectedLine: null,
      maxHeight: 0,
      currentHeight:0,
      maxWidth: 0,
      currentWidth: 0,
      stage: null,
      pointNum: 0,
      lineNum: 0,
      scope: null,
      path: null,
      points: [], //https://konvajs.org/docs/vue/index.html
      lines: [],
      testpoints: [], //for testing only, remove for prod
      dragId: null,
      ratioToDecimal: 1,
      data: "the cat in the hat knows a lot about that",
      file: "waveform",
      type: ".prsm",
      configKonva: {
        width: 0,
        height: 0,
      },
      circleConfig: { //we have default konva object properties to copy every time we make a new object (add it to its respective list)
        x: 300,
        y: 50,
        radius: 20,
        fill: 'red',
        stroke: 'black',
        strokeWidth: 4,
        id: "test",
      },
      defaultLine: { //we have default konva object properties to copy every time we make a new object (add it to its respective list)
        fill: 'black',
        tension: 0,
        //bezier: true,
        points: [],
        stroke: "black",
        strokeWidth: 4,
        bezier : false,
      },
      defaultCircle: { //we have default konva object properties to copy every time we make a new object (add it to its respective list)
        config: {
          x: 300,
          y: 50,
          radius: 5,
          fill: 'black',
          stroke: 'black',
          strokeWidth: 4,
          id: "test",
          draggable: false,
        },
        relX: 0,
        relY: 0,
        numId: 0,
        windowResizeCounter: 0,
      }

    };
  },
  methods: {
    increase() {
      this.data++;
    },
    movePointX() {
      if (!this.pointIsSelected) return;
      this.selectedPoint.config.x = parseFloat(this.rangeXval);
      this.drawLines();
    },
    movePointY() {
      if (!this.pointIsSelected) return;
      this.selectedPoint.config.y = parseFloat(this.rangeYval);
      this.drawLines();
    },
    moveLine() {
      if (!this.lineIsSelected) return;

      let pointArr = this.selectedLine.config.points;
      //two cases: positive slider and negative slider
      if(this.rangecurve != 0){

      
        //this.selectedLine.config.points = [pointArr[0],pointArr[1],(pointArr[0]+pointArr[2])/2,((pointArr[1]+pointArr[3])/2) - this.rangeCurve((pointArr[1]+pointArr[3])/2),pointArr[2],pointArr[3]];
        
        
        //otherwise change y value of midpoint
        this.selectedLine.config.points[3] = ((pointArr[1]+pointArr[5])/2) - this.rangeCurve*((pointArr[1]+pointArr[5])/2);
        
        let x = JSON.parse(JSON.stringify(this.defaultCircle));
        x.config.x = this.selectedLine.config.points[2];
        x.config.y = this.selectedLine.config.points[3];
        this.testpoints =  this.testpoints.concat([x]);
        this.selectedLine.config.tension = Math.abs(parseFloat(this.rangeCurve)); //tension parameter (who knows what this does?)
        console.log(this.selectedLine.config.tension);
      }
      // else if(this.rangeCurve < 0){
      //   this.selectedLine.config.points[3] = ((pointArr[1]+pointArr[3])/2) - this.rangeCurve*((pointArr[1]+pointArr[3])/2);
        
      //   let x = JSON.parse(JSON.stringify(this.defaultCircle));
      //   x.config.x = this.selectedLine.config.points[2];
      //   x.config.y = this.selectedLine.config.points[3];
      //   this.testpoints =  this.testpoints.concat([x])
      //   this.selectedLine.config.tension = (parseFloat(this.rangeCurve)); //tension parameter (who knows what this does?)
      // }
      else if (this.rangeCurve == 0)
      {
        this.selectedLine.config.points = [pointArr[0],pointArr[1],pointArr[4],pointArr[5]];
        this.selectedLine.config.tension = 0.5; //tension parameter (who knows what this does?)
      }
      

    },
    resizeHandler(e) {
      //e is the event, but don't need to prevent default



      //e.preventDefault();
      let rect = this.$refs.wavetable.getBoundingClientRect();
      
      //grab new heights
      let canvasNewHeight = rect.width;
      let canvasNewWidth = rect.height;
      //console.log(rect.width)
      this.ratioToDecimal = 1;
      while (rect.width / this.ratioToDecimal > 2*Math.PI  )
      {
        this.ratioToDecimal++;
      }

      //this happens the initial time when the thing is moved, it will mess up and try to make everything infinity
      if(this.currentHeight == 0 || this.currentWidth == 0){
        console.log("Somethnig was infinity")
        this.currentHeight =  canvasNewHeight;
        this.currentWidth = canvasNewWidth;
        return;
      }

      //def does not work lol
      let heightRatio = canvasNewHeight / this.currentHeight;
      let widthRatio = canvasNewWidth / this.currentWidth;
      
      //console.log("Old Height : "+this.currentHeight,"Old Width :" + this.currentWidth,"New Height : " + canvasNewHeight, "New Width : " + canvasNewWidth, "Height Ratio : " + heightRatio, "Width Ratio :" + widthRatio);


      this.currentHeight =  canvasNewHeight;
      this.currentWidth = canvasNewWidth;
      
      
      this.points.map(x =>{
        // console.log(x);
        x.config.x = x.config.x * heightRatio;
        x.config.y = x.config.y * widthRatio;
      });
      this.drawLines();
    },
    testFunc(e) {
      console.log(e);
    //only here for debugging purposes
    },
    //resets the wavetable editor
    newFile() { //basically does the same thing as mounted() check down there for more 
      this.lines = [];
      this.points = [];
      let rect = this.$refs.wavetable.getBoundingClientRect();
      this.configKonva.height = rect.height;
      this.configKonva.width = rect.width;
      console.log(rect);
      let x = JSON.parse(JSON.stringify(this.defaultCircle));
      let y = JSON.parse(JSON.stringify(x));
      x.config.x = 0;
      x.config.y = rect.height / 2;
      y.config.x = rect.width;
      console.log(x.config.x);
      y.config.y = rect.height / 2;
      x.numId = 0;
      y.numId = 1;
      this.pointNum = 2;
      this.points = this.points.concat([x, y]);
      let defaultLineConfig = JSON.parse(JSON.stringify(this.defaultLine));
      defaultLineConfig.points = [0, rect.height / 2, rect.width, rect.height / 2];
      let line = {
        config: defaultLineConfig,
        lineId: this.lineNum,
      }
      this.lineNum++;
      this.lines = [line];
    },
    //drawLines looks at all the points we have available, and connects the closest points on the x axis via line. Done by filtering points by x Position
    //https://stackoverflow.com/questions/25835510/draw-curved-line-between-two-points <- oh boy this one is going to be a doozy
    drawLines() {
      let linestmp = []
      this.lineNum = 0;
      //sort points by x values
      let sortedArr = this.points.sort((a, b) => { return a.config.x - b.config.x });
      for (let i = 0; i < sortedArr.length; i++) {
        if (i < sortedArr.length - 1) {
          let defaultLineConfig = JSON.parse(JSON.stringify(this.defaultLine));
          //modified
          defaultLineConfig.points = [sortedArr[i].config.x, sortedArr[i].config.y, (sortedArr[i].config.x + sortedArr[i+1].config.x )/2,     (sortedArr[i].config.y + sortedArr[i+1].config.y )/2       , sortedArr[i + 1].config.x, sortedArr[i + 1].config.y]; //for bezier curves, pass 6 points, [startx, starty, midx, midy, endx, endy]
          defaultLineConfig.bezier = false //if tention is 0, then bezier will not work, tension needs to be something more than 0 or it will fail
          defaultLineConfig.tension = .5 // when the tension is set, you can have a tensioned line without bezier being set, but you will need a midpoint, and want to keep the tension the same and just move the midpoint up and down
          let line = {
            config: defaultLineConfig,
            lineId: this.lineNum,
          }
          console.log(line)
          this.lineNum++;
          linestmp = linestmp.concat([line]);
          //this.lines = this.lines.concat([line]);

        }
          // need to add logic that checks curve in original line and readds curve here
      }
      this.lines = linestmp;
    },
    
    //this updates the lines while you drag a point around
    handleDrag(e) {
      //DEPRECATED (saving code for later)
      let event = e.evt;
      let rect = this.$refs.wavetable.getBoundingClientRect();
      let xPos = Math.round(event.x - rect.x);
      let yPos = Math.round(event.y - rect.y);
      var indexDrag = this.dragId;
      var point = this.points.filter((x) => { return x.config.index == indexDrag })
      var sameX = this.points.filter((x) => {return x.config.x == e.target.attrs.x});
      point.forEach((x) => {
        //for each function, but should always have one item in array.
        //(x.config.x < 0) ? (x.config.x =0,e.target.attrs.x = 0) : (x.config.x > this.stage.attrs.width) ? (x.config.x = this.stage.attrs.width,e.target.attrs.x = this.stage.attrs.width) : x.config.x = xPos;
        // (x.config.x == 0 && sameX.length == 1) ? (x.config.x = 0,e.target.attrs.x=0) : (x.config.x == this.stage.attrs.width && sameX.length == 1) ? (x.config.x = this.stage.attrs.width,e.target.attrs.x = this.stage.attrs.width) : x.config.x = xPos;
        // (e.target.attrs.y <= 0) ? (x.config.y = 0,e.target.attrs.y =0) : (e.target.attrs.y == this.stage.attrs.height) ? (x.config.y = this.stage.attrs.height,e.target.attrs.y = this.stage.attrs.height) : (x.config.y = yPos);
        x.config.y = yPos;
      });
      this.drawLines();
    },
    //event that fires when a click happens: we see if there is a line / point there. if there is, select it. 
    //if no point exists, create a new point there
    //saving for later: https://codesandbox.io/s/github/konvajs/site/tree/master/vue-demos/basic_demo?from-embed=&file=/src/App.vue
    //need to normalize all lines to between 0 and 2 PI x and 0 and 1 y. will do later.
    clickLine(e) {
      // console.log(e);
      let event = e.evt;
      let rect = this.$refs.wavetable.getBoundingClientRect();
      if (!this.lineIsSelected)
      {
        if (this.pointIsSelected)
        {
          this.dehighlight();
        }
        this.lineIsSelected = true;
        let lineSelected = this.lines.filter((x) => {
          return (e.target.attrs.points[0] == x.config.points[0] && e.target.attrs.points[2] == x.config.points[2]);
        });
        // console.log(lineSelected)
        this.selectedLine = lineSelected[0];
        this.highlightLine(lineSelected[0]);
      }
      else
      {
        
        this.dehighlight();
      }

    },
    clickPoint(e) { 
      let event = e.evt;
      let self = this;
      let rect = this.$refs.wavetable.getBoundingClientRect();
      let xPos = Math.round(event.x - rect.x);
      let yPos = Math.round(event.y - rect.y);
      //proximity check sees if there is a point close enough to your click to warrent highlighting a point. has a magic number of 10, should probably be a scale factor. oh well
      let proximityCheck = this.points.filter((x) => { return (Math.sqrt((x.config.x - xPos) * (x.config.x - xPos) + (x.config.y - yPos) * (x.config.y - yPos)) < 10) })
      //selected a point
      if (proximityCheck.length > 0) {
        if (!self.pointIsSelected) {
          self.pointIsSelected = true;
          proximityCheck.forEach(x => { //should always only be one of these 
            self.selectedPoint = x;
          });
          self.highlightPoint(self.selectedPoint);
        }
        else {
        self.dehighlight();
        self.pointIsSelected = false;
        }
      }
      else {
              if (self.pointIsSelected) {
        self.points = this.points.map((x) => {
          x.config.fill = 'black';
          x.config.strokeWidth=4;
          x.config.radius =5;
          return x ;
        });
        self.pointIsSelected = false;
      }
        this.drawLines();
      }
    
    },
    highlightPoint(point){
      this.selectedPoint = point;
      this.selectedPoint.config.fill = 'red';
      this.selectedPoint.config.stroke = 'black';
      this.selectedPoint.config.strokeWidth = 1;
      this.selectedPoint.config.radius = 8;
      this.pointIsSelected = true;
      this.rangeXval =  this.selectedPoint.config.x; //set sliders to the point's config value
      this.rangeYval = this.selectedPoint.config.y;
    },
    highlightLine(line){ //changes selectedLine to the line given, and changes that line's config to reflect it's selection visually. same is true for highlightPoint(point) above but for points
      this.selectedLine = line;
      this.selectedLine.config.fill='red';
      this.selectedLine.config.stroke='red';
      this.selectedLine.config.strokeWidth = 8;
      this.lineIsSelected = true;
      
    },  
    dehighlight(){
      if(this.selectedPoint == null && this.selectedLine == null) return;
      if (this.selectedPoint)
      {
      this.selectedPoint.config.fill = 'black'; //changes config of selectedPoint back to defaults. below does the same for line. also moves the selected point out of this.selectedPoint
      this.selectedPoint.config.strokeWidth=4;
      this.selectedPoint.config.radius =5;
      this.selectedPoint = null;
      this.pointIsSelected = false;
      this.rangeXval = 0.0;
      this.rangeYval = 0.0;
      }
      if (this.selectedLine)
      {
        this.selectedLine.config.fill='black';
        this.selectedLine.config.stroke='black';
        this.selectedLine.config.strokeWidth = 4;
        this.rangeCurve = 0.0;
        this.selectedLine = null;
        this.lineIsSelected = false;
        this.rangeCurve = 0.0;
      }
    },
    addPoint(){
      let point = JSON.parse(JSON.stringify(this.defaultCircle)); //copy circle config
      point.config.x = this.stage.attrs.width/2;
      point.config.y = this.stage.attrs.height/2;
      point.config.index = this.pointNum;
      this.pointNum++;
      //if a point was selected, deselect it
      this.dehighlight();
      //select the point we just drew
      this.highlightPoint(point);
      this.points = this.points.concat([point]);
      this.drawLines();
    },
    deletePoint() { //index should be order of creation I think
      if (!this.pointIsSelected || this.selectedPoint.config.index == 0 || this.selectedPoint.config.index == 1) // no deleting the two edge points!
      {
        return;
      }
      this.points = this.points.filter((x) => {
        if (x.config.index == this.selectedPoint.config.index)
        {
          return false;
        }
        return true;
      });
      this.dehighlight();
    },  
    //https://stackoverflow.com/questions/2897619/using-html5-javascript-to-generate-and-save-a-file
    //saves the .prsm file
    saveFile() { 
      let rect = this.$refs.wavetable.getBoundingClientRect()
      let canvasWidth = rect.width;
      let canvasHeight = rect.height;


      let sortedArr = this.points.sort((a, b) => { return a.config.x - b.config.x }); //sorts points by x value ascending
      this.data = "START\n";
      this.data = this.data + sortedArr.length + "\n";

      this.data = this.data +"WIDTH : " + canvasWidth+"\nHEIGHT : " + canvasHeight +'\n';

      for(let i = 0; i < sortedArr.length; i++){
        this.data = this.data + sortedArr[i].config.x + " " + sortedArr[i].config.y + "\n";
      }
      this.data = this.data + "END";

      // console.log(this.$root);
      var pom = document.createElement("a");
      pom.setAttribute("href", "data:text/plain;charset=utf-8," + encodeURIComponent(this.data));
      pom.setAttribute("download", "" + this.file + this.type);
      if (document.createEvent) {
        var event = document.createEvent("MouseEvents");
        event.initEvent("click", true, true);
        pom.dispatchEvent(event);

      }
      else {
        pom.click();
      }
    },

    openFile(){
      
      this.points = [];
      this.lines = [];
      console.log(this.points,this.lines)
      this.lineNum = 0;
      let vue = this;
      //grab current heights because you will need this for scale factor
      let rect = this.$refs.wavetable.getBoundingClientRect();
      let currentCanvasHeight = rect.height; //used for scale factor
      let currentCanvasWidth = rect.width; //used for scale factor
      console.log(currentCanvasHeight, currentCanvasWidth)

      const content = document.querySelector('.content');
      const [file] = document.querySelector('input[type=file]').files;
      const reader = new FileReader();
      let circleConfig = JSON.parse(JSON.stringify(this.defaultCircle));
      let fileText = null;
      if (file) {
        this.points = []
        reader.readAsText(file);
        reader.onload = function(x){
          //x.target.result will have the text from the file
          console.log(x)
          fileText = x.target.result;
          fileText = fileText.split("\n")
          console.log(fileText);
          
          let lineCount = parseInt(fileText[1]);
          vue.lineNum = lineCount
          let previousCanvasWidth = parseInt(fileText[2]); 
          let previousCanvasHeight = parseInt(fileText[3]);
          //console.log(previousCanvasHeight, previousCanvasWidth)
          let scaleFactorY = currentCanvasHeight / previousCanvasHeight;
          let scaleFactorX = currentCanvasWidth / previousCanvasWidth;
          //console.log(scaleFactorX, scaleFactorY)
          //this is where you travese the point section and grab all the points
          let pointLines = fileText.slice(4, 4+parseInt(lineCount))
          let newPoints = []
          console.log("ready to compute new points")
          let numId = 0;
          pointLines.forEach(element => {

            //console.log("new point!")
            //let point = JSON.parse(JSON.stringify(this.parent.defaultCircle));
            //console.log("LINE")
            let line = element.split(" ")
            let newCircle = circleConfig;
            let config ={
              fill: "black",
              id :"test",
              radius:5,
              stroke:'black',
              strokeWidth:4,
              x: 0,
              y:0,
              index: numId,
              endpoin: false,
            }
            if(numId == 0 || numId+1 == lineCount){
              console.log("ENDPOINT")
              config.endpoint = true;
            }
            let circle = {
              config : config,
              relX: 0,
              relY: 0,
              numId: numId,
              windowResizeCounter: 0,
            }
            //console.log(vue.circleConfig)
            circle.config.x = parseInt(line[0]) * scaleFactorX //apply new scale factor to points
            circle.config.y = parseInt(line[1]) * scaleFactorY //apply new scale factor to points
            console.log(circle)
            vue.points = vue.points.concat(circle) ; //add the thingy
            //console.log("added the thingy")
            numId += 1;
          });
          //console.log(newPoints)
          this.points = newPoints;
          console.log(vue.points,vue.lines)
          vue.drawLines()

        }}
    },
  },
  //https://dev.to/sandrarodgers/listen-for-and-debounce-window-resize-event-in-vuejs-2pn2
  //need this to be able to handle resize events
  created() {
      window.addEventListener("resize",this.resizeHandler);
  },
  unmounted() {
    console.log("Unmounted has been called!!!!!!");
    window.removeEventListener("resize",this.resizeHandler);
  },
  mounted: function () { //mounted is the code that runs when this component gets "called" to the DOM (mounted). idk the details just think of it as your stuff that runs on startup
    //inserts two points on the wavetable at the boundry edges.
    let rect = this.$refs.wavetable.getBoundingClientRect();
    this.configKonva.height = rect.height;
    this.configKonva.width = rect.width;
    while (rect.width / this.ratioToDecimal > 2*Math.PI  )
    {
      this.ratioToDecimal++;
    }

    console.log(this.ratioToDecimal, rect.width,rect.height);
    let x = JSON.parse(JSON.stringify(this.defaultCircle)); //JSON.parse does a deep copy of our object, so we have the correct amount of config objects rather than one
    let y = JSON.parse(JSON.stringify(x));
    x.config.x = 0;
    x.config.y = rect.height / 2;
    x.config.index = this.pointNum;
    y.config.x = rect.width;
    y.config.y = rect.height / 2;
    y.config.index = 1;
    x.numId = 0;
    y.numId = 1;
    this.pointNum = 2;
    this.points = this.points.concat([x, y]); //add the point to our list of points, which will dynamically update
    let defaultLineConfig = JSON.parse(JSON.stringify(this.defaultLine)); //same idea for line
    defaultLineConfig.points = [0, rect.height / 2, rect.width, rect.height / 2];
    let line = {
      config: defaultLineConfig,
      lineId: this.lineNum,
    }
    this.lineNum++;
    this.lines = [line];
    this.stage = this.$refs.stage.getStage(); //stores stage object for use later
    this.maxHeight = rect.height;
    this.maxWidth = rect.width;
    this.stage.draw();
  },
  watch:{ //watch runs a function every time the watched value changes
    rangeXval: function(value) {
      this.movePointX();
    },
    rangeYval: function(value) {
      this.movePointY();
    },
    rangeCurve: function(value) {
      this.moveLine();
    }
  },
  components: {BarChart}
}

</script>
  
<style>

.stage{
  cursor: crosshair;
  width: 100% !important;
  height: 100% !important;
  border: 5px solid black;
  border-radius: 10px;
  display: block;
  margin: auto;
  box-shadow: 0 10px 8px -8px black;
}


  .stage-wrapper {
    /*https://stackoverflow.com/questions/12121090/responsively-change-div-size-keeping-aspect-ratio
    /* width within the parent.
       can be any percentage. */
    width: 100%;
    background-color: pink;
}
.stage-wrapper:before {
    content: "";
    float: left;

    /* essentially the aspect ratio. 100% means the
       div will remain 100% as tall as it is wide, or
       square in other words.  */
    padding-bottom: 43%;
}
/* this is a clearfix. you can use whatever
   clearfix you usually use, add
   overflow:hidden to the parent element,
   or simply float the parent container. */
.stage-wrapper:after {
    content: "";
    display: table;
    clear: both;
}

.wavetable {
  
  /* background-color: yellow;
  background-image: url("../../Images/aboutBackground4.jpg");
  background-size: cover;  */
  /* background:
        linear-gradient(red, transparent),
        linear-gradient(to top left, lime, transparent),
        linear-gradient(to top right, blue, transparent);
    background-blend-mode: screen; */
background-color: blue;

  /* opacity: 0.5; */
  background: rgba(0, 0, 0, 0.2);
  margin: auto;
  outline: 2px solid black;
  /* min-width: 50%; */
  /* min-height: 300px; */
  max-width: 70%;
  /* height: 70%; */
  /* min-height: 400px; */
  box-sizing: border-box;

}

.mainbody {
  /* background-color: #97b4b3; */
  background-image: url("../../Images/aboutBackground2.png");
  background-size: cover;
  width: 100%;
  margin-top: 0px;
  height: 975px;
  padding: 4px;
  padding-top: 10px; 
}

.point-adjustment {
  margin-left: 5%;
  margin-top: 5px;
  width: 90%;
  height: 30%;
}

/* Necessary for keeping seperate rows between add, delete point and new, open, and save file.*/
.new-open-save {
  
}

.saveFile-button {
  display: inline-block;
  width: 100px;
  height: 30px;
  margin: auto;
  margin-top: 10px;
  margin-right: 10px;
  margin-bottom: 10px;
  padding:2px;
  color: white;
  font-family: Impact;
  font-size: 18px;
  background-color: #333333;
  border: 2px solid #333333;
  border-radius: 8px 8px;
  cursor: pointer;
}

.saveFile-button:hover {
  background-color: red;
}

.newFile-button {
  display: inline-block;
  width: 100px;
  height: 30px;
  margin: auto;
  margin-top: 10px;
  margin-right: 10px;
  margin-bottom: 10px;
  padding:2px;
  color: white;
  font-family: Impact;
  font-size: 18px;
  background-color: #333333;
  border: 2px solid #333333;
  border-radius: 8px 8px;
  cursor: pointer;
}

.newFile-button:hover {
  background-color: red;
}

.openFile-button {
  display: inline-block;
  width: 100px;
  height: 30px;
  margin: auto;
  margin-top: 10px;
  margin-right: 10px;
  margin-bottom: 15px;
  padding: 2px;
  color: white;
  font-family: Impact;
  font-size: 18px;
  background-color: #333333;
  border: 2px solid #333333;
  border-radius: 8px 8px;
  cursor: pointer;
}

.openFile-button:hover {
  background-color: red;
}


.add-point {
  display: inline-block;
  width: 100px;
  height: 30px;
  margin: auto;
  margin-top: 10px;
  margin-right: 10px;
  margin-bottom: 10px;
  padding:2px;
  color: black;
  font-family: Impact;
  font-size: 18px;
  background-color: #95B8D1;
  border: 2px solid black;
  border-radius: 8px 8px;
  cursor: pointer;
}

.add-point:hover {
  background-color: #6050DC;
}

.delete-point {
  display: inline-block;
  width: 120px;
  height: 30px;
  margin: auto;
  margin-top: 10px;
  margin-right: 10px;
  padding: 2px;
  color: black;
  font-family: Impact;
  font-size: 18px;
  background-color: #EDAFB8;
  border: 2px solid black;
  border-radius: 8px 8px;
  cursor: pointer;
}

.delete-point:hover {
  background-color: #AA0000;
}

/* Slider css data from W3School tutorial https://www.w3schools.com/howto/howto_js_rangeslider.asp*/
.slidecontainer {
  margin: auto;
  width: 25%; /* Width of the outside container */
  
}

/* The slider itself */
.slider {
  -webkit-appearance: none;  /* Override default CSS styles */
  appearance: none;
  width: 100%; /* Full-width */
  height: 25px; /* Specified height */
  background: #ffffff; /* Grey background */
  outline: none; /* Remove outline */
  opacity: 0.7; /* Set transparency (for mouse-over effects on hover) */
  -webkit-transition: .2s; /* 0.2 seconds transition on hover */
  transition: opacity .2s;
  border: 2px solid black;
  border-radius: 5px;
}

/* Mouse-over effects */
.slider:hover {
  opacity: 1; /* Fully shown on mouse-over */
}

/* The slider handle (use -webkit- (Chrome, Opera, Safari, Edge) and -moz- (Firefox) to override default look) */
.slider::-webkit-slider-thumb {
  -webkit-appearance: none; /* Override default look */
  appearance: none;
  width: 25px; /* Set a specific slider handle width */
  height: 25px; /* Slider handle height */
  background: #3e4444; /* Green background */
  cursor: pointer; /* Cursor on hover */
  border: 1px solid black;
  border-radius: 4px;
}

.slider::-moz-range-thumb {
  width: 25px; /* Set a specific slider handle width */
  height: 25px; /* Slider handle height */
  background: #3e4444; /* Green background */
  cursor: pointer; /* Cursor on hover */
  border-radius: 3px;
}
</style>

