const chk = document.getElementById('chk');
const chk1 = document.getElementById('chk1');
const chk2 = document.getElementById('chk2');
const chk3 = document.getElementById('chk3');

chk.addEventListener('change', () => {
    if(chk.checked){
        console.log(true);
        window.location='file:///c%3A/Users/guilh/OneDrive/Documents/GitHub/ProjectsMicrocontrollers/ESP32/Test/testWEB/index.html/PH';
    }else{
        console.log(false);
    }
});

chk1.addEventListener('change', () => {
    if(chk1.checked){
        console.log(true);
    }else{
        console.log(false);
    }
});

chk2.addEventListener('change', () => {
    if(chk2.checked){
        console.log(true);
    }else{
        console.log(false);
    }
});

chk3.addEventListener('change', () => {
    if(chk3.checked){
        console.log(true);
    }else{
        console.log(false);
    }
});