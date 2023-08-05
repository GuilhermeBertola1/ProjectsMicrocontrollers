const chk = document.getElementById("chk");
const chk1 = document.getElementById("chk1");
const chk2 = document.getElementById("chk2");
const chk3 = document.getElementById("chk3");

chk.addEventListener("change", () => {
  if (chk.checked) {
    console.log(true);
    window.location = "/PH";
  } else {
    console.log(false);
  }
});

chk1.addEventListener("change", () => {
  if (chk1.checked) {
    console.log(true);
  } else {
    console.log(false);
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

window.onload = function () {
  let x = 0;
  let arrayList = [];

  function monitorarValor() {
    x += 5;
    let valor = 0;

    valor = parseInt(Math.random() * 200);

    arrayList.push(valor);
    document.getElementById("monitoramento").innerHTML = arrayList
      .map((y) => `<li class="x">valor sensor:${y}°C</li>`)
      .join("");

    addData(valor);
  }
  setInterval(monitorarValor, 1000);
};

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
