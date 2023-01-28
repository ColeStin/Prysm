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
    data() {
      return {
        chartData: {
    labels: ['January', 'February', 'March', 'April', 'May', 'June', 'July'],    
    datasets: [
    {
      
      label: 'waveform',
      backgroundColor: '#f87979',
      data: [40, 39, 10, 40, 39, 80]
    }
  ]
        },
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
                      display:false
                  }
              },
              y: {
                  grid: {
                      display:false
                  }
              },
          },
        }
      }
    }
  }
  </script>