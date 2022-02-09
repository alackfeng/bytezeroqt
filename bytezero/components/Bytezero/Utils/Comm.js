.pragma library

function bytesToSize(bytes) {
    bytes = parseInt(bytes)
    if (bytes === 0) return '0 B';
    var k = 1024;
    let sizes = ['B','KB', 'MB', 'GB', 'TB', 'PB', 'EB', 'ZB', 'YB'];
    let i = Math.floor(Math.log(bytes) / Math.log(k));
    return (bytes / Math.pow(k, i)).toFixed(2) + ' ' + sizes[i];
}

function formatDateString(ms) {
    return new Date(ms).toDateString()
}

function formatZero(num, len=2) {
    if(String(num).length > len) return num;
    return (Array(len).join(0) + num).slice(-len);
}

function formatTsToProgress(s) {
    s = parseInt(s)
    var l = s / 60
    var hour = l / 60
    var minute = l % 60
    var second = s % 60
    hour = formatZero(Math.floor(hour))
    minute = formatZero(Math.floor(minute))
    second = formatZero(Math.floor(second))
    return "" + hour + ":" + minute + ":" + second

}


Date.prototype.format = function (fmt) { //author: meizz
    var o = {
        "M+": this.getMonth() + 1,
        "d+": this.getDate(),
        "h+": this.getHours(),
        "m+": this.getMinutes(),
        "s+": this.getSeconds(),
        "q+": Math.floor((this.getMonth() + 3) / 3),
        "S": this.getMilliseconds()
    };
    if (/(y+)/.test(fmt)) fmt = fmt.replace(RegExp.$1, (this.getFullYear() + "").substr(4 - RegExp.$1.length));
    for (var k in o)
    if (new RegExp("(" + k + ")").test(fmt)) fmt = fmt.replace(RegExp.$1, (RegExp.$1.length === 1) ? (o[k]) : (("00" + o[k]).substr(("" + o[k]).length)));
    return fmt;
}

function formatTimeString(ms, fmt) {
    return new Date(ms).format(fmt);
}
