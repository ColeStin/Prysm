<template>
    <Line
      id="my-chart-id"
      :options="chartOptions"
      :data="chartData"
    />
  </template>
  <script>
  import {
  Chart as ChartJS,
  CategoryScale,
  LinearScale,
  PointElement,
  LineElement,
} from 'chart.js'
  import { Line } from 'vue-chartjs'
  ChartJS.register(
  CategoryScale,
  LinearScale,
  PointElement,
  LineElement,
)
  export default {
    name: 'BarChart',
    components: { Line },
    props: {chartData: {}},
    mounted: () => {
     console.log(this.chartData);
    },
    data() {
      return {
        
        chartOptions: {
          responsive: true,
          maintainAspectRatio: true,
          autoPadding: true,
          scales: {
              x: {
                  grid: {
                      display:false
                  },
                  ticks: {
                      display:true
                  }
              },
              y: {
                  grid: {
                      display:true
                  }
              },
          },
        }
      }
    }
  }
  </script>