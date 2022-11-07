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
-->

<template>
  <!-- Main body which will contain wave table as well as buttons for user input-->
  <div class="mainbody">
    
    <div class="wavetable" ref="wavetable">
      <v-stage ref="stage" :config="configKonva" >
        <v-layer ref="layer">
          <v-line v-for="item in lines" :key="item.lineId" :config="item.config" @click="clickLine"></v-line>
          <v-circle v-for="item in points" :key="item.numId" :config="item.config" @click="clickPoint"></v-circle>
          <!--<v-circle v-for="item in testpoints" :key="item.numId" :config="item.config" ></v-circle> -->
        </v-layer>
      </v-stage>
    </div>
    <div class="point-adjustment">
      <div class="add-point" @click="addPoint">Add Point</div> <!-- Creates a point in the center of the graph-->
      <div class="delete-point" @click="deletePoint" >Delete Point</div> <!-- Deletes a selected point-->
      <div class="slidecontainer">
        <a>X: {{rangeXval}}</a> <!-- For adjusting the x value of a selected point-->
        <input type="range"  min="0" :max="maxWidth" v-model="rangeXval" class="slider" step=".5" :disabled="!pointIsSelected || (selectedPoint&&selectedPoint.config.index == 0) || (selectedPoint&&stage&&selectedPoint.config.index == 1)" id="myRange">
        <a>Y: {{rangeYval}}</a> <!-- For adjusting the y value of a selected point-->
        <input type="range" min="0"  :max="maxHeight" v-model="rangeYval" class="slider" step=".5" :disabled="!pointIsSelected" id="myRange2">
        <a>Curve: {{rangeCurve}}</a> <!-- For adjusting the curvature of a selected line-->
        <input type="range" min="-1" max="1" step=".1" v-model="rangeCurve" class="slider" id="myRange" :disabled="!lineIsSelected">
      </div>

    </div>
  </div>
  <!-- Bottom section of file containing save and new file buttons-->
  <div class="background">
    <div class="save-button" @click="saveFile()">Save File</div>
    <div class="new-button" @click="newFile()">New File</div>
  </div>
</template>
  
<script>


export default {
  data: function () {
    return {
      //range values
      rangeXval: 0.0,
      rangeYval: 0.0,
      rangeCurve: 0.0,
      selectedPoint: null,
      pointIsSelected: false,
      lineIsSelected: false,
      selectedLine: null,
      maxHeight: 0,
      maxWidth: 0,
      stage: null,
      pointNum: 0,
      lineNum: 0,
      scope: null,
      path: null,
      points: [], //https://konvajs.org/docs/vue/index.html
      lines: [],
      testpoints: [], //for testing only, remove for prod
      dragId: null,

      data: "the cat in the hat knows a lot about that",
      file: "waveform",
      type: ".prsm",
      configKonva: {
        width: 0,
        height: 0,
      },
      circleConfig: {
        x: 300,
        y: 50,
        radius: 20,
        fill: 'red',
        stroke: 'black',
        strokeWidth: 4,
        id: "test",
      },
      defaultLine: {
        fill: 'black',
        tension: 0,
        points: [],
        stroke: "black",
        strokeWidth: 4,
      },
      defaultCircle: {
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
      if (this.rangeCurve > 0)
      {
        if (pointArr.length == 4)
        {
        this.selectedLine.config.points = [pointArr[0],pointArr[1],(pointArr[0]+pointArr[2])/2,((pointArr[1]+pointArr[3])/2) - this.rangeCurve*((pointArr[1]+pointArr[3])/2),pointArr[2],pointArr[3]];
      
        }
        else
        {
        this.selectedLine.config.points[3] = ((pointArr[1]+pointArr[3])/2) - this.rangeCurve*((pointArr[1]+pointArr[3])/2);
        }
        let x = JSON.parse(JSON.stringify(this.defaultCircle));
        x.config.x = this.selectedLine.config.points[2];
        x.config.y = this.selectedLine.config.points[3];
        this.testpoints =  this.testpoints.concat([x])
        this.selectedLine.config.tension = parseFloat(this.rangeCurve);

      }
      else if (this.rangeCurve < 0)
      {
        let curve = Math.abs(this.rangeCurve);
        if (pointArr.length == 4)
        {
        this.selectedLine.config.points = [pointArr[0],pointArr[1],(pointArr[0]+pointArr[2])/2,this.stage.attrs.height,pointArr[2],pointArr[3]];
        }
        this.selectedLine.config.tension = parseFloat(curve);
      }
      else if (this.rangeCurve == 0)
      {
        this.selectedLine.config.points = [pointArr[0],pointArr[1],pointArr[4],pointArr[5]];
        this.selectedLine.config.tension = parseFloat(this.rangeCurve);
      }
      // this.selectedLine.config.points = this.selectedLine.config.points.concat([(this.selectedLine.config.points[0]+this.selectedLine.config.points[2])/2,this.stage.attrs.height]);
      
      // console.log(this.selectedLine);
      
      // console.log(this.selectedLine.config.tension)
    },
    resizeHandler(e) {
      //def does not work lol
      console.log(e);
      let heightRatio = 1;
      let widthRatio = 1;
    
      this.points.map(x =>{
        // console.log(x);
        x.config.x = x.config.x * widthRatio;
        x.config.y = x.config.y * heightRatio;
      });
      this.drawLines();
    },
    testFunc(e) {
      console.log(e);
    //only here for debugging purposes
    },
    //resets the wavetable editor
    newFile() {
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
          defaultLineConfig.points = [sortedArr[i].config.x, sortedArr[i].config.y, sortedArr[i + 1].config.x, sortedArr[i + 1].config.y];
          let line = {
            config: defaultLineConfig,
            lineId: this.lineNum,
          }
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

      let proximityCheck = this.points.filter((x) => { return (Math.sqrt((x.config.x - xPos) * (x.config.x - xPos) + (x.config.y - yPos) * (x.config.y - yPos)) < 10) })
      //selected a point
      if (proximityCheck.length > 0) {
        if (!self.pointIsSelected) {
          self.pointIsSelected = true;
          proximityCheck.forEach(x => {
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
      this.rangeXval =  this.selectedPoint.config.x;
      this.rangeYval = this.selectedPoint.config.y;
    },
    highlightLine(line){
      this.selectedLine = line;
      this.selectedLine.config.fill='red';
      this.selectedLine.config.stroke='red';
      this.selectedLine.config.strokeWidth = 8;
      this.lineIsSelected = true;
      this.rangeCurve = this.selectedLine.config.tension;
    },  
    dehighlight(){
      if(this.selectedPoint == null && this.selectedLine == null) return;
      if (this.selectedPoint)
      {
      this.selectedPoint.config.fill = 'black';
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
      let point = JSON.parse(JSON.stringify(this.defaultCircle));
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
    deletePoint() {
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
      let sortedArr = this.points.sort((a, b) => { return a.config.x - b.config.x });
      this.data = "START\n";
      this.data = this.data + sortedArr.length + "\n";
      for(let i = 0; i < sortedArr.length; i++){
        this.data = this.data + sortedArr[i].config.x + " " + sortedArr[i].config.y + "\n";
      }
      this.data = this.data + "END";

      console.log(this.$root);
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
  },
  //https://dev.to/sandrarodgers/listen-for-and-debounce-window-resize-event-in-vuejs-2pn2
  //need this to be able to handle resize events
  created() {
      window.addEventListener("resize",this.resizeHandler);
  },
  unmounted() {
    window.removeEventListener("resize",this.resizeHandler);
  },
  mounted: function () {
    //inserts two points on the wavetable at the boundry edges.
    let rect = this.$refs.wavetable.getBoundingClientRect();
    this.configKonva.height = rect.height;
    this.configKonva.width = rect.width;
    let x = JSON.parse(JSON.stringify(this.defaultCircle));
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
    this.points = this.points.concat([x, y]);
    let defaultLineConfig = JSON.parse(JSON.stringify(this.defaultLine));
    defaultLineConfig.points = [0, rect.height / 2, rect.width, rect.height / 2];
    let line = {
      config: defaultLineConfig,
      lineId: this.lineNum,
    }
    this.lineNum++;
    this.lines = [line];
    this.stage = this.$refs.stage.getStage();
    this.maxHeight = rect.height;
    this.maxWidth = rect.width;
    this.stage.draw();
  },
  watch:{
    rangeXval: function(value) {
this.movePointX();
    },
    rangeYval: function(value) {
this.movePointY();
    },
    rangeCurve: function(value) {
      this.moveLine();
    }
  }
}

</script>
  
<style>

.wavetable-class {

  cursor: crosshair;
  width: 100% !important;
  height: 100% !important;
  border: 5px solid black;
  border-radius: 10px;
  display: block;
  margin: auto;
  box-shadow: 0 10px 8px -8px black;

}

.wavetable {
  margin: auto;
  outline: 2px solid black;
  min-width: 400px;
  min-height: 300px;
  width: 90%;
  height: 70%;
  box-sizing: border-box;
}

.mainbody {
  background-color: #bdcebe;
  width: 100%;
  margin-top: 0px;
  height: 100%;
  padding: 4px;
}

.point-adjustment {
  margin-left: 5%;
  margin-top: 5px;
  width: 90%;
  height: 30%;

}

.background {
  color: red;
  background-color: #3e4444;
  width: 100%;
  height: 100%;
}

.save-button {
  float: left;
  margin: auto;
  width: 8%;
  height: 8%;
  text-align: center;
  color: black;
  font-family: Impact;
  background-color: #b4a7d6ff;
  border: 2px solid #8e7cc3;
  padding: 4px;
  border-radius: 8px 8px;
  cursor: pointer;
}

.new-button {
  float: right;
  margin: auto;
  width: 8%;
  height: 8%;
  text-align: center;
  color: black;
  font-family: Impact;
  background-color: #b4a7d6ff;
  border: 2px solid #8e7cc3;
  padding: 4px;
  border-radius: 8px 8px;
  cursor: pointer;
}

.add-point {
  float: left;
  width: 100px;
  height: 25px;
  margin: auto;
  margin-top: 10px;
  padding:2px;
  color: black;
  font-family: Impact;
  font-size: 18px;
  background-color: #c42021;
  border: 2px solid black;
  border-radius: 8px 8px;
  cursor: pointer;
}

.delete-point {
  float: right;
  width: 100px;
  height: 25px;
  margin: auto;
  margin-top: 10px;
  padding:2px;
  color: black;
  font-family: Impact;
  font-size: 18px;
  background-color: #c42021;
  border: 2px solid black;
  border-radius: 8px 8px;
  cursor: pointer;
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

