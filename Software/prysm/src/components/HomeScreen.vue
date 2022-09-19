<template>
    <div class="example">{{data}}<div @click="increase()">click here to increase count!!!!</div></div>
  </template>
  
  <script>
  export default {
    data: function() {
      return {
        data: 0,
      }
    },
    methods: {
        increase() {
            this.data++;
        }
    }
  }
  </script>
  
  <style>
  .example {
    color: red;
  }
  </style>