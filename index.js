// let a = 3;
// let b = 6;

// function getData(a,b){
//     return new Promise((resolve, reject) => {
//         setTimeout(() => {
//             resolve(a+b);
//         },3000);
//     })
// }

// async function Youy(){
//     const data = await getData(a,b);
//     console.log(data);   
// }
// Youy();

// async function getData1() {
//     const data = await fetch("https://api.open-meteo.com/v1/forecast?latitude=52.52&longitude=13.41&current_weather=true&hourly=temperature_2m,relativehumidity_2m,windspeed_10m");
//     const file = await data.json(JSON);
//     console.log(file.generationtime_ms)


//     fetch("https://api.open-meteo.com/v1/forecast?latitude=52.52&longitude=13.41&current_weather=true&hourly=temperature_2m,relativehumidity_2m,windspeed_10m")
//         .then(data => data.json(JSON))
//         .then(result => {
//             for(const i in result.current_weather)
//                 console.log(i);
//             })
// }
// getData1();

// let array = [2, 43, 34, 5, 5]
// let a = array.reduce((i, sum) => {
//     return i+sum        
// })
// console.log(a);
// isNaN() //If number then return true either false

// let p1 = new Promise(function(resolve, reject) {
//     setTimeout(resolve, 500, 'p1');
// });

// let p2 = new Promise(function(resolve, reject) {
//     setTimeout(resolve, 1000, 'p2');
// });

// let p3 = new Promise(function(resolve, reject) {
//     setTimeout(resolve, 1200, 'p3');
// });

// let p4 = new Promise(function(resolve, reject) {
//     setTimeout(reject, 300, 'p4');
// });

// let p5 = new Promise(function(resolve, reject) {
//     setTimeout(resolve, 800, 'p5');
// });

// let promise = Promise.all([p1.catch(function() {}), p2.catch(function() {}), p3.catch(function() {}), p4.catch(function() {}), p5.catch(function() {})]);

// promise
// .then(function(data) {
//     data.forEach(function(data) {
//         console.log(data);
//     });
// })
// .catch(function(error) {
//     console.error('error', error);
// });



// let arr = [176,36,104,125,188,152,101,47,51,65,39,174,29,55,13,138,79,81,175,178,42,108,24,80,183,190,123,20,139,22,140,62,58,137,68,148,172,76,173,189,151,186,153,57,142,105,133,114,165,118,56,59,124,82,49,94,8,146,109,14,85,44,60,181,95,23,150,97,28,182,157,46,160,155,12,67,135,117,2,25,74,91,71,98,127,120,130,107,168,18,69,110,61,147,145,38];
// let n = 3016;
// let maxSum = 240; 
// let cnt = 0;
// arr.sort((a,b)=>a-b);

// const is_it = (r) => {
//     let left = 0;
//     let right = arr.length - 1;
//     while (left <= right) {
//         let mid = left + (right - left) / 2;
//         if (arr[mid] == r)
//             return false;
//         else if (arr[mid] > r)
//             right = mid - 1;
//         else
//             left = mid + 1;
//         console.log(arr[mid]);
//     }
//     return true;
// }
// let sum = 0;

// for (let i = 1; i <= n; i++) {
//     if (is_it(i) == true) {
//         if (sum + i > maxSum)
//             break;
//         sum +=i;
//         cnt += 1;
//         // console.log(i);
//     }
// }
// console.log("The numebr : ",cnt,"  The sum is ",sum);





function f(list) {
    let index = 0;
    function die() {
        let ans = list[index];

        index = (index + 1) % list.length;
        return ans;
    }
    return die;
}
const temp = f([12, 3, 4, 5, 76]);
temp.die();








