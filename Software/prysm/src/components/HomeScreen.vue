<template>
    <!-- Top navbar area to show name of app and soon to be info area button-->
    <div class="navbar">
      <div class="title">
        Prysm
        <!-- Info image which will soon link to about modal with credits to all makers of the project-->
        <img class="info" src="../../public/info_icon.png" alt="About"/>
      </div>
    </div>

    <!-- Main body which will contain wave table as well as buttons for user input-->
    <div class= "mainbody">
    <div class="wavetable"  ref="wavetable">
      <v-stage ref="stage" :config="configKonva" @dragstart="increase" @dragend="increase" @click="selectElement" >
        <v-layer ref="layer">
          <v-circle v-for="item in symbols" :key="item" :config="item.circleConfig"></v-circle>
        </v-layer>
        </v-stage>
    </div>  
    </div>
    <!-- Bottom section of file containing save and new file buttons-->
    <div class="background">
      <div class="save-button" @click="saveFile()">Save File</div>
      <div class="new-button" @click="newFile(data,file,type)">New File</div>
    </div>
</template>
  
  <script>


  export default {
    data: function () {
        return {
            scope: null,
            path: null,
            symbols: [], //https://konvajs.org/docs/vue/index.html
            data: "the cat in the hat knows a lot about that",
            file: "waveform",
            type: ".prsm",
            wavetableEdit: {
                selected: null,
                selectedType: null,
            },
            configKonva: {
              width:0,
              height: 0,
            },
            circleConfig: {
            x: 30,
            y: 50,
            rotation: 0,
            id: "2",
            numPoints: 5,
            innerRadius: 30,
            outerRadius: 50, fill: '#89b717',
            opacity: 0.8,
            draggable: true,
            }

        };
    },
    methods: {
        increase() {
            this.data++;
        },
        //event that fires when a click happens: we see if there is a line / point there. if there is, select it. 
        //saving for later: https://codesandbox.io/s/github/konvajs/site/tree/master/vue-demos/basic_demo?from-embed=&file=/src/App.vue
        selectElement(e) {
            //console.log(this.$refs.wavetable.getBoundingClientRect());
             console.log(e);
             let event = e.evt;
            let rect = this.$refs.wavetable.getBoundingClientRect();
            let xPos = Math.round(event.x - rect.x);
            let yPos = Math.round(rect.y - event.y + rect.height);
            console.log(xPos);
            console.log(yPos);
        },
        //https://stackoverflow.com/questions/2897619/using-html5-javascript-to-generate-and-save-a-file
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
  .wavetable-class{

        cursor: crosshair;
        width: 100% !important;
        height: 100% !important;
        border: 5px solid black;
        border-radius: 10px;
        display: block;
        margin: auto;
        box-shadow: 0 10px 8px -8px black;
    
  }
  .info{
    height: 40px;
    width: 40px;
    margin-top: 12px;
    float: right;
  }
  .wavetable{
    margin: auto;
    outline: 2px solid black;
    width: 90%;
    height: 90%;

  }
  .title{
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
    height: 400px;
    padding: 4px;
  }

  .background {
    color: red;
    background-color: #3e4444;
    width: 100%;
    height: 100%;
  }
  .save-button{
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
    border-radius: 8px 8px ;
    cursor: pointer;
  }
  .new-button{
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
    border-radius: 8px 8px ;
    cursor: pointer;
  }
  </style>