const chk = document.getElementById("chk");
const chk1 = document.getElementById("chk1");
const chk2 = document.getElementById("chk2");
const chk3 = document.getElementById("chk3");

let arrayList = [];

function monitorarValorSM(array) {
  return function () {
    let xhttp = new XMLHttpRequest();
    let valor = 0;

    xhttp.open("GET", "/SM", true);
    xhttp.send();
    console.log(xhttp.status);

    if (xhttp.status === 0) {
      valor = parseInt(Math.random() * 200);
      array.push(valor);
      document.getElementById("monitoramento").innerHTML = array
        .map((y) => `<li class="x">valor sensor:${y}°C</li>`)
        .join("");

      addData(valor);
    }
  };
}

function monitorarValorPHON() {
  let xhttp = new XMLHttpRequest();
  xhttp.open("GET", "/PHON", true);
  xhttp.send();
  console.log(xhttp.status);
}

function monitorarValorPHOFF() {
  let xhttp = new XMLHttpRequest();
  xhttp.open("GET", "/PHOFF", true);
  xhttp.send();
  console.log(xhttp.status);
}

chk.addEventListener("change", () => {
  if (chk.checked) {
    console.log(true);
    monitorarValorPHON();
  } else {
    console.log(false);
    monitorarValorPHOFF();
  }
});

chk1.addEventListener("change", () => {
  if (chk1.checked) {
    const timer = setInterval(monitorarValorSM(arrayList), 3000);
    chk1.addEventListener("change", () => {
      clearInterval(timer);
    });
  }
});

chk2.addEventListener("change", () => {
  if (chk2.checked) {
    console.log(true);
  } else {
    console.log(false);
  }
});

chk3.addEventListener("change", () => {
  if (chk3.checked) {
    console.log(true);
  } else {
    console.log(false);
  }
});

let inicio = {
  labels: ["s3"],
  datasets: [
    {
      label: "Valor Medido",
      data: [0],
    },
  ],
};

let config = {
  responsive: true,
  maintainAspectRatio: false,
  scales: {
    y: {
      beginAtZero: true,
    },
  },
};

let ctx = document.getElementById("myChart").getContext("2d");
let myChart = new Chart(ctx, {
  type: "line",
  data: inicio,
  options: config,
});

function addData(newData) {
  let data = myChart.data;
  data.labels.push("s" + 3);
  data.datasets[0].data.push(newData);
  myChart.update();
}
