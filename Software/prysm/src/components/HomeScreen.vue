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
-->

<template>
  <!-- Top navbar area to show name of app and soon to be info area button-->
  <div class="navbar">
    <div class="title">
      Prysm
      <!-- Info image which will soon link to about modal with credits to all makers of the project-->
      <img class="info" @click = "openAboutPage()" src="../../public/info_icon.png" alt="About" />
      <!-- <div class="info-button" @click="openAboutPage()">About Page</div> -->
    </div>
  </div>


  <!-- Main body which will contain wave table as well as buttons for user input-->
  <div class="mainbody">
    <div class="wavetable" ref="wavetable">
      <v-stage ref="stage" :config="configKonva" @dragstart="(e) => {handleDragStart(e)}" @dragend="handleDragEnd"
        @dragmove="(e) => {handleDrag(e)}" @click="selectElement">
        <v-layer ref="layer">
          <v-line v-for="item in lines" :key="item.lineId" :config="item.config"></v-line>
          <v-circle v-for="item in points" :key="item.numId" :config="item.config"></v-circle>
        </v-layer>
      </v-stage>
    </div>
    <div class="point-adjustment">
      <div class="add-point" >Add Point</div> <!-- Creates a point in the center of the graph-->
      <div class="delete-point" >Delete Point</div> <!-- Deletes a selected point-->
      <div class="slidecontainer">
        <a>X:</a> <!-- For adjusting the x value of a selected point-->
        <input type="range" min="1" max="100" value="50" class="slider" id="myRange">
        <a>Y:</a> <!-- For adjusting the y value of a selected point-->
        <input type="range" min="1" max="100" value="50" class="slider" id="myRange">
        <a>Curve:</a> <!-- For adjusting the curvature of a selected line-->
        <input type="range" min="1" max="100" value="50" class="slider" id="myRange">
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
      pointNum: 0,
      lineNum: 0,
      scope: null,
      path: null,
      points: [], //https://konvajs.org/docs/vue/index.html
      lines: [],
      dragId: null,
      selectedPoint: null,
      isSelected: false,
      data: "the cat in the hat knows a lot about that",
      file: "waveform",
      type: ".prsm",
      wavetableEdit: {
        selected: null,
        selectedType: null,
      },
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
        strokeWidth: 2,
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
          draggable: true,
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

    openAboutPage() {
        
    },
    testFunc() {
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
    drawLines() {
      this.lines = [];
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
          this.lines = this.lines.concat([line]);

        }
      }
    },
    handleDragEnd() {
      this.selectedPoint = null;
    },
    //this updates the lines while you drag a point around
    handleDrag(e) {
      let event = e.evt;
      let rect = this.$refs.wavetable.getBoundingClientRect();
      let xPos = Math.round(event.x - rect.x);
      let yPos = Math.round(event.y - rect.y);
      var indexDrag = this.dragId;
      var point = this.points.filter((x) => { return x.config.index == indexDrag })
      point.forEach((x) => {
        x.config.x = xPos;
        x.config.y = yPos;
      });
      this.drawLines();
    },
    //this lets the component know which element we are dragging
    handleDragStart(e) {
      let self = this;
      console.log(e);
      this.dragId = e.target.attrs.index;
      var point = this.points.filter((x) => { 
        return x.config.index == this.dragId; })
        console.log(this.points);
      point.forEach((x) => {
      self.selectedPoint = x;

      })
      if (self.isSelected) {
        self.selectedPoint.config.fill = 'black';
        self.selectedPoint.config.stroke = 'black';
        self.selectedPoint.config.radius = 5;
        self.selectedPoint.config.strokeWidth = 4;
        self.isSelected = false;
      }
        
      self.selectedPoint.config.fill = 'red';
          self.selectedPoint.config.stroke = 'black';
          self.selectedPoint.config.strokeWidth = 1;
          self.selectedPoint.config.radius = 8;
          self.isSelected = true;
    },
    //event that fires when a click happens: we see if there is a line / point there. if there is, select it. 
    //if no point exists, create a new point there
    //saving for later: https://codesandbox.io/s/github/konvajs/site/tree/master/vue-demos/basic_demo?from-embed=&file=/src/App.vue
    //need to normalize all lines to between 0 and 2 PI x and 0 and 1 y. will do later.
    selectElement(e) {
      let event = e.evt;
      let self = this;
      let rect = this.$refs.wavetable.getBoundingClientRect();
      let xPos = Math.round(event.x - rect.x);
      let yPos = Math.round(event.y - rect.y);

      let proximityCheck = this.points.filter((x) => { return (Math.sqrt((x.config.x - xPos) * (x.config.x - xPos) + (x.config.y - yPos) * (x.config.y - yPos)) < 10) })
      //selected a point
      if (proximityCheck.length > 0) {
        if (!self.isSelected) {
          self.isSelected = true;
          proximityCheck.forEach(x => {
            self.selectedPoint = x;
          });
          self.selectedPoint.config.fill = 'red';
          self.selectedPoint.config.stroke = 'black';
          self.selectedPoint.config.strokeWidth = 1;
          self.selectedPoint.config.radius = 8;
          self.isSelected = true;
        }
        else {
          self.points = self.points.map((x) => {
          x.config.fill = 'black';
          x.config.strokeWidth=4;
          x.config.radius =5;
          return x ;
        });
        self.isSelected = false;
        }
      }
      else {
              if (self.isSelected) {
        self.points = this.points.map((x) => {
          x.config.fill = 'black';
          x.config.strokeWidth=4;
          x.config.radius =5;
          return x ;
        });
        self.isSelected = false;
      }
        let point = JSON.parse(JSON.stringify(this.defaultCircle));
        point.config.x = xPos;
        point.config.y = yPos;
        point.config.index = this.pointNum;
        point.numId = this.pointNum;
        this.pointNum++;
        this.points = this.points.concat([point]);
        //possible optimization: pass in point made, only rerender points to left and right
        //also need to : add x and y by normalizing here to -1 and 1 and 0 - 2pi
        this.drawLines();
      }
    },
    //https://stackoverflow.com/questions/2897619/using-html5-javascript-to-generate-and-save-a-file
    //saves the .prsm file
    saveFile() {
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
  mounted: function () {
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
    let stage = this.$refs.stage.getStage();

    stage.draw();
  },
}

</script>
  
<style>
.navbar {
  background-color: #3e4444;
  width: 100%;
  height: 65px;
  padding: 0px;
}

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

.info {
  height: 40px;
  width: 40px;
  margin-top: 12px;
  float: right;
}

.wavetable {
  margin: auto;
  outline: 2px solid black;
  width: 90%;
  height: 70%;

}

.title {
  color: #e6e2d3;
  float: center;
  font-size: 50px;
  text-align: center;
  font-family: Impact;
  margin-left: 1%;
  margin-right: 1%;
}

.about {
  padding-left: 90%;
  margin-top: -33px;
  color: #e6e2d3;
  font-family: Impact;
}

.mainbody {
  background-color: #bdcebe;
  width: 100%;
  margin-top: 0px;
  height: 550px;
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
  width: 8%;
  height: 10%;
  margin: auto;
  margin-top: 10px;
  color: black;
  font-family: Impact;
  background-color: #c42021;
  border: 2px solid black;
  padding: 4px;
  border-radius: 8px 8px;
  cursor: pointer;
}

.delete-point {
  float: right;
  width: 8%;
  height: 10%;
  margin: auto;
  margin-top: 10px;
  color: black;
  font-family: Impact;
  background-color: #c42021;
  border: 2px solid black;
  padding: 4px;
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
  background: #11e9f5; /* Green background */
  cursor: pointer; /* Cursor on hover */
  border: 2px solid black;
}

.slider::-moz-range-thumb {
  width: 25px; /* Set a specific slider handle width */
  height: 25px; /* Slider handle height */
  background: #11e9f5; /* Green background */
  cursor: pointer; /* Cursor on hover */
  border: 2px solid black;
}
</style>

