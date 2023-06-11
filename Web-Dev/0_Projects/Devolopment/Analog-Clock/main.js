// new Date().getHours();
// new Date().getMinutes();
// new Date().getSeconds();
setInterval(() => {
    d = new Date;
    hTime = d.getHours();
    mTime = d.getMinutes();
    STime = d.getSeconds();
    hRotation = 30 * hTime + mTime / 2;
    mRotation = 6 * mTime;
    sRotation = 6 * STime;
    hour.style.transform = `rotate(${hRotation}deg)`;
    minute.style.transform = `rotate(${mRotation}deg)`;
    second.style.transform = `rotate(${sRotation}deg)`;
}, 1000);