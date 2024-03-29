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
       2/12 - Alex - Editing of UI for min/max/range buttons
-->

<template>
  <!-- Main body which will contain wave table as well as buttons for user input-->
  <div class="mainbody">
    <div class="chartcontainer">
      <Line v-if="loaded" ref="chartElement" id="my-chart-id" :options="chartOptions" :data="data" />
    </div>

    <div class="point-adjustment">

      <!-- Seperates New, Open, and Save File from Above Row-->
      <div class="new-open-save">
        <!-- Resets the wavetable to original state-->
        <div class="newFile-button" @click="newFile()">New File
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor"
            class="bi bi-file-earmark-plus-fill" viewBox="0 0 16 16">
            <path
              d="M9.293 0H4a2 2 0 0 0-2 2v12a2 2 0 0 0 2 2h8a2 2 0 0 0 2-2V4.707A1 1 0 0 0 13.707 4L10 .293A1 1 0 0 0 9.293 0zM9.5 3.5v-2l3 3h-2a1 1 0 0 1-1-1zM8.5 7v1.5H10a.5.5 0 0 1 0 1H8.5V11a.5.5 0 0 1-1 0V9.5H6a.5.5 0 0 1 0-1h1.5V7a.5.5 0 0 1 1 0z" />
          </svg>
        </div>
        <!-- Opens an existing .prsm file -->
        <div class="openFile-button">
          <label for="open-input" style="cursor: pointer;">
            Open File
            <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-files"
              viewBox="0 0 16 16">
              <path
                d="M13 0H6a2 2 0 0 0-2 2 2 2 0 0 0-2 2v10a2 2 0 0 0 2 2h7a2 2 0 0 0 2-2 2 2 0 0 0 2-2V2a2 2 0 0 0-2-2zm0 13V4a2 2 0 0 0-2-2H5a1 1 0 0 1 1-1h7a1 1 0 0 1 1 1v10a1 1 0 0 1-1 1zM3 4a1 1 0 0 1 1-1h7a1 1 0 0 1 1 1v10a1 1 0 0 1-1 1H4a1 1 0 0 1-1-1V4z" />
            </svg>
            <input id="open-input" type="file" ref="fileIn" @change="openFile()" style="display: none;" />
          </label>
        </div>

        <div class = "input-boxes">
        Name File:
          <input id = "fileNameInput" type = "text" required = "required"> 
        </div>

           <!-- Saves .prsm file to computer-->
        <div class="saveFile-button" @click="saveFile()">Save File
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor"
            class="bi bi-file-earmark-arrow-down-fill" viewBox="0 0 16 16">
            <path
              d="M9.293 0H4a2 2 0 0 0-2 2v12a2 2 0 0 0 2 2h8a2 2 0 0 0 2-2V4.707A1 1 0 0 0 13.707 4L10 .293A1 1 0 0 0 9.293 0zM9.5 3.5v-2l3 3h-2a1 1 0 0 1-1-1zm-1 4v3.793l1.146-1.147a.5.5 0 0 1 .708.708l-2 2a.5.5 0 0 1-.708 0l-2-2a.5.5 0 0 1 .708-.708L7.5 11.293V7.5a.5.5 0 0 1 1 0z" />
          </svg>
        </div>

        <!-- Templated Options-->
        <!-- Opens premade .prsm files from computer-->
        <!-- document.getElementById("select-box").value -->
        <div class="select-container"> 
          <select class = "select-box">
            <option value = ""> Templated Options (4)</option>
            <option value = "linearTemplate"> Linear Curve - 0.1x + 5 </option>
            <option value = "sinTemplate"> Sin Curve - 50 sin (8x) </option>
            <option value = "cosTemplate"> Cos Curve - 50 cos (3x) </option>
            <option value = "tanTemplate"> Tan Curve - 50 tan (2x) </option>
          </select>
        </div>
      </div>  

      <div class="function-input">
        <div class="input-boxes">
          Function: <input type='text' v-model="functionIn" />
          Minimum: <input type="text" v-model="inputMin" /> Maximum: <input type="number" v-model="inputMax" /> 
          <!-- <button @click="addFunction()">submit</button> -->
          <div class="submit-button" @click="addFunction()">Submit
            
        </div>
        </div>
        <div class="previous-functions">
        </div>
      </div>
    </div>
  </div>
  <!-- Bottom section of file containing save and new file buttons-->
  <div class="background">
    <!-- <p> &nbsp;</p>
    <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p> -->
          <!-- <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p>
          <p> &nbsp;</p> -->
  </div>
</template>
  
<script>
import { create, all } from "mathjs";
const math = create(all);
import {
  Chart as ChartJS,
  CategoryScale,
  LinearScale,
  PointElement,
  LineElement,
} from 'chart.js'
import { Chart, Line } from 'vue-chartjs'
ChartJS.register(
  CategoryScale,
  LinearScale,
  PointElement,
  LineElement,
)
export default {
  data: function () {
    return { //think of the return section as the private member vars of a class (this component). They can be accessed with this.whatever (unless you've changed what this is)
      exportData: "the cat in the hat knows a lot about that",
      //Below is removed because satisfied in saveFile() function
      //file: "wavelength"
      type: ".prsm",
      chart: null,
      loaded: true,
      functionIn: '',
      inputMin: 1,
      inputMax: 2048,
      ceiling: 127,
      floor: -128,
      data: { datasets: [], labels: [] },
      chartData: {
        labels: [0],
        datasets: [
          {

            label: 'waveform',
            backgroundColor: '#f87979',
            data: [10, 20, 30, 40]
          }
        ]
      },
      chartOptions: {
        elements: {
          point: {
            radius: 0
          }
        },
        responsive: true,
        maintainAspectRatio: true,
        autoPadding: true,
        scales: {
          x: {
            grid: {
              display: false
            },
            ticks: {
              display: false
            },
            suggestedMax:2048
          },
          y: {
            grid: {
              display: false
            },
            beginAtZero: false,
            suggestedMin: -128,
            suggestedMax: 127,
          },
        },
      }
    };

  },
  components: { Line },
  computed: {
    mutableData() { return this.chartData },
    mutableOptions() { return this.chartOptions },
  },
  methods: {
    increase() {
      console.log(this.chartData.datasets[0].data);
    },
    addFunction() { // this inputs your data into the chart and then displays it
      // console.log('functionIN,min,max',this.functionIn,this.inputMin,this.inputMax);

     
      let tmp = this.functionIn;
      // if (document.getElementById("select-box").value == "sinTemplate")
      // {
      //   let tmp = "50 sin (8x)";
      // }
      //gotta wrap in parentheses so if there are two numbers next to each other the one being put in still gets multiplied correctly
      //a la 2(x)2 = 2*x*2 not 222 if x=2
      tmp = tmp.replaceAll('x', '(x)');
      let result;
      let tmp2;
      for (let i = this.inputMin; i <= this.inputMax; i++) {
        // console.log(this.inputMin,this.inputMax,'min and max');
        //you have to use an inner temp here because otherwise youre replacing x in the string on the first pass and then there are no more strings.
        tmp2 = tmp.replaceAll('x', i);
        try {
          //mathjs parses your input and evaluates
          result = math.evaluate(tmp2);
        } catch (error) {
          //ha ha no error checking here yet
          console.log('error', tmp2);
          return;
        }
        if (result > this.ceiling) {
          result = this.ceiling;
        }
        else if (result < this.floor) {
          result = this.floor;
        }
        console.log('i,res', i, result);
        this.chartData.datasets[0].data[i - 1] = result;
        // console.log('i plus this.chartData.datasets[0].data[i-1]',i,this.chartData.datasets[0].data[i-1]);
      }
      // console.log(this.chartData);
      this.renderChart();
    },
    renderChart() {
      let tmp = JSON.parse(JSON.stringify(this.chartData));
      this.data = tmp;
    },
    testFunc(e) {
      console.log(this.data.datasets[0].data)
    },
    //resets the wavetable editor
    newFile() {
      this.chartData.labels = [];
      for (let i = 0; i < this.inputMax; i++) {
        this.chartData.labels = this.chartData.labels.concat([i]);
        this.chartData.datasets[0].data[i] = 0;
      }
      this.data = JSON.parse(JSON.stringify(this.chartData));

    },
    //https://masteringjs.io/tutorials/vue/file
    //file opening with VUE
    openFile() {
      console.log(this.$refs.fileIn.files)
      //this section is ripped and modified from the website directly above
      const reader = new FileReader();
      if (this.$refs.fileIn.files[0].name.includes(".prsm")) {
        reader.onload = (res) => {
          let tmp = res.target.result.split('\n');
          this.chartData.labels = [];
          for (let i = 0; i < this.inputMax; i++) {
            this.chartData.labels = this.chartData.labels.concat([i]);
            this.chartData.datasets[0].data[i] = tmp[i] * 100;
          }
          this.data = JSON.parse(JSON.stringify(this.chartData));
        };
        reader.onerror = (err) => console.log(err);
        reader.readAsText(this.$refs.fileIn.files[0]);
      } else {
        console.log('error in file input!')
      }
    },
    resizeHandler() {
      console.log(this.$refs.chartElement.chart.resize())
      // this.$refs.chartElement.renderChart(this.data,this.chartOptions)
    },
    //drawLines looks at all the points we have available, and connects the closest points on the x axis via line. Done by filtering points by x Position
    //https://stackoverflow.com/questions/25835510/draw-curved-line-between-two-points <- oh boy this one is going to be a doozy

    //https://stackoverflow.com/questions/2897619/using-html5-javascript-to-generate-and-save-a-file
    //saves the .prsm file
    saveFile() {
      this.exportData = "";
      let tmp = this.data.datasets[0].data;
      for (let i = 0; i < tmp.length; i++) {
        this.exportData = this.exportData + "" + math.round(tmp[i])+ "\n";
      }
      //end character
      this.exportData = this.exportData + "W";

      var pom = document.createElement("a");
      pom.setAttribute("href", "data:text/plain;charset=utf-8," + encodeURIComponent(this.exportData));

      //takes input from "Name File" textbox and saves it to be what file will be named. 
      this.file = document.getElementById("fileNameInput").value;

      //if filename input is left empty, it will just be called "wavelength.prsm"
      if (this.file == "")
      {
        this.file = "wavelength"
      }
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
  mounted() { //mounted is the code that runs when this component gets "called" to the DOM (mounted). idk the details just think of it as your stuff that runs on startup
    // this.chartData.datasets[0].data = [];
    console.log('env',process.env.VUE_APP_TEST_VAR)
    for (let i = 0; i < this.inputMax; i++) {
      this.chartData.labels = this.chartData.labels.concat([i]);
      this.chartData.datasets[0].data[i] = 0;
    }
    this.data = JSON.parse(JSON.stringify(this.chartData));

  },
  watch: { //watch runs a function every time the watched value changes

  },
}

</script>
  
<style>
.chartcontainer {
  margin-left: 15%;
  margin-right: 15%;

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
.new-open-save {}

.saveFile-button {
  display: inline-block;
  width: 100px;
  height: 30px;
  margin: auto;
  margin-top: 10px;
  margin-right: 10px;
  margin-left: 5px;
  margin-bottom: 10px;
  padding: 2px;
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
  padding: 2px;
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
  padding: 2px;
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

.submit-button {
  display: inline-block;
  width: 100px;
  height: 30px;
  margin: auto;
  margin-top: 10px;
  margin-bottom: 10px;
  margin-left: 5px;
  padding: 2px;
  color: white;
  font-family: Impact;
  font-size: 18px;
  background-color: #333333;
  border: 2px solid #333333;
  border-radius: 8px 8px;
  cursor: pointer;
}

.submit-button:hover {
  background-color: red;
}

.nameFile-button {
  display: inline-block;
  width: 100px;
  height: 30px;
  margin: auto;
  margin-top: 10px;
  margin-bottom: 10px;
  padding: 2px;
  color: white;
  font-family: Impact;
  font-size: 18px;
  background-color: #333333;
  border: 2px solid #333333;
  border-radius: 8px 8px;
  cursor: pointer;
}

.nameFile-button:hover {
  background-color: red;
}

.select-container
{
display: inline-block;
/* display: flex; */
justify-content: center;
position: relative;
}

.select-box:hover
{
  background-color: orange;
 
}

.select-box
{
display: inline-block;
appearance: none;
padding: 5px 5px 5px 5px;
width: 100%;
color: white;
background-color: #333333;
font-size: 18px;
border-width: 0px;
border-color: white;
border-radius: 5px;
cursor: pointer;
}

.input-boxes
{
  display: inline-block;
  /* position: relative; */
  /* width: 250px; */
  /* margin-left: 5px; */
}

.input-boxes input
{
  /* width: 100%; */
  padding: 10px;
  width: 100px;
  border: 1px solid rgba(255, 255, 255, 0.25);
  border-radius: 6px;
  background: #1d2b3a;
  outline: none;
  color: #fff;
  font-size: 1em; 
  outline: none;
}

.input-boxes span
{
  position: absolute;
  /* left: 0; */
  padding: 10px;
  pointer-events: none;
  font-size: 1em;
  color: rgba(255, 255, 255, 0.25);
  text-transform: uppercase;
}

.input-boxes input:valid ~ span,
.input-boxes input:focus ~ span /* ~ span does not work */
{
  color: #00dfc4;
}
/* Slider css data from W3School tutorial https://www.w3schools.com/howto/howto_js_rangeslider.asp*/
.slidecontainer {
  margin: auto;
  width: 25%;
  /* Width of the outside container */
}

/* The slider itself */
.slider {
  -webkit-appearance: none;
  /* Override default CSS styles */
  appearance: none;
  width: 100%;
  /* Full-width */
  height: 25px;
  /* Specified height */
  background: #ffffff;
  /* Grey background */
  outline: none;
  /* Remove outline */
  opacity: 0.7;
  /* Set transparency (for mouse-over effects on hover) */
  -webkit-transition: .2s;
  /* 0.2 seconds transition on hover */
  transition: opacity .2s;
  border: 2px solid black;
  border-radius: 5px;
}

/* Mouse-over effects */
.slider:hover {
  opacity: 1;
  /* Fully shown on mouse-over */
}

/* The slider handle (use -webkit- (Chrome, Opera, Safari, Edge) and -moz- (Firefox) to override default look) */
.slider::-webkit-slider-thumb {
  -webkit-appearance: none;
  /* Override default look */
  appearance: none;
  width: 25px;
  /* Set a specific slider handle width */
  height: 25px;
  /* Slider handle height */
  background: #3e4444;
  /* Green background */
  cursor: pointer;
  /* Cursor on hover */
  border: 1px solid black;
  border-radius: 4px;
}

.slider::-moz-range-thumb {
  width: 25px;
  /* Set a specific slider handle width */
  height: 25px;
  /* Slider handle height */
  background: #3e4444;
  /* Green background */
  cursor: pointer;
  /* Cursor on hover */
  border-radius: 3px;
}
</style>

