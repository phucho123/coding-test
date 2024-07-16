const backgroundColor = document.getElementsByTagName("body")[0];
const result = document.getElementById("result");

document.getElementById("myform").addEventListener("submit", function (event) {
    event.preventDefault();
    var formData = new FormData(this);

    var formObj = {};
    formData.forEach(function (value, key) {
        formObj[key] = value;
    });
    backgroundColor.style.backgroundColor = formObj.color;
    result.innerHTML = `
        <div>
        <span><strong>User name: </strong></span>
        <span>${formObj.username}</span>
        </div>
        <div>
        <span><strong>User age: </strong></span>
        <span>${formObj.userage}</span>
        </div>
        <div>
        <span><strong>Color: </strong></span>
        <span style="color:${formObj.color}">${formObj.color}</span>
        </div>
    `
    console.log(formObj);
})