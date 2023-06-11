let input = document.querySelector('#input');
let searchBtn = document.querySelector('#search');
let apiKey = '213e3a2b-a6f4-48a1-8bd4-12da52598dc7';
let notFound = document.querySelector('.not__found');
let explanation = document.querySelector('.definition');
let audio = document.querySelector('.audio');
let loading = document.querySelector('.loading');

searchBtn.addEventListener('click', function(e){
    e.preventDefault();
    // clear previous data
    notFound.innerText = '';
    explanation.innerText = '';
    audio.innerHTML = '';
    // Get input
    let query = input.value;
    // console.log(query);
    if (query === ''){
        alert("Enter Your Query.");
        return;
    }
    getData(query);
});

async function getData(query){
    loading.style.display = 'block';
    const responses = await fetch(`https://www.dictionaryapi.com/api/v3/references/learners/json/${query}?key=${apiKey}`);
    const data = await responses.json();
    // console.log(data);
    // if search result not found
    if (data.length == 0){
        loading.style.display = 'none';
        notFound.innerText = 'search result not found';
        return;
    }
    // if search result is a suggestion
    if (typeof data[0] === 'string'){
        loading.style.display = 'none';
        let heading = document.createElement('h3');
        heading.innerText = 'Did you mean?'
        notFound.appendChild(heading);
        data.forEach(element => {
            let suggestion = document.createElement('span');
            suggestion.classList.add('suggested');
            suggestion.innerHTML = element;
            notFound.appendChild(suggestion);
        });
        return;
    }
    // let definition = data[0].shortdef[0];
    // console.log(definition);
    // explanation.innerHTML = definition;
    loading.style.display = 'none';
    let len = data[0].shortdef.length;
    // console.log(len);
    // ans.forEach(element => {
    //     explanation.innerHTML = element;
    // });
    let finalAns = "";
    for (var i = 0; i < len; i++){
        let ans = data[0].shortdef[i];
        console.log(ans);
        // explanation.innerText = ans;
        finalAns += ans;
        finalAns += ", ";
    }
    // console.log(finalAns);
    // if (finalAns == "") {
    //     explanation.innerText = "Result not Found!";
    //     return;
    // }
    explanation.innerText = finalAns;

    // Pronunciation of Search query
    // console.log(data);
    // try {
        const sound = data[0].hwi.prs[0].sound.audio;
    // } catch (error) {
    //     explanation.innerText = "Sound Not Found!\n" + error;
    //     // console.log("Sound Not Found!\n" + error);
    //     return;
    // }
    // console.log(sound);
    if (sound){
        renderSound(sound);
    }
}
function renderSound(sound){
    // https://media.merriam-webster.com/audio/prons/en/us/mp3
    let subFolder = sound.charAt(0);
    let soundUrl = `https://media.merriam-webster.com/audio/prons/en/us/mp3/${subFolder}/${sound}.mp3?key=${apiKey}`;
    let aud = document.createElement('audio');
    aud.src = soundUrl;
    aud.controls = true;
    audio.appendChild(aud);
}