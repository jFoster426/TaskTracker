#ifndef index_h
#define index_h

const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="shortcut icon" href="data:image/x-icon;base64,AAABAAEAAQEAAAEAIAAwAAAAFgAAACgAAAABAAAAAgAAAAEAIAAAAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAP//AAAAAA==" />
    <!-- We can't use this if we don't have WiFI!! -->
    <!-- <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css"> -->
    <style>
    /* W3.CSS 4.15 December 2020 by Jan Egil and Borge Refsnes */
    html{box-sizing:border-box}*,*:before,*:after{box-sizing:inherit}
    /* Extract from normalize.css by Nicolas Gallagher and Jonathan Neal git.io/normalize */
    html{-ms-text-size-adjust:100%;-webkit-text-size-adjust:100%}body{margin:0}
    article,aside,details,figcaption,figure,footer,header,main,menu,nav,section{display:block}summary{display:list-item}
    audio,canvas,progress,video{display:inline-block}progress{vertical-align:baseline}
    audio:not([controls]){display:none;height:0}[hidden],template{display:none}
    a{background-color:transparent}a:active,a:hover{outline-width:0}
    abbr[title]{border-bottom:none;text-decoration:underline;text-decoration:underline dotted}
    b,strong{font-weight:bolder}dfn{font-style:italic}mark{background:#ff0;color:#000}
    small{font-size:80%}sub,sup{font-size:75%;line-height:0;position:relative;vertical-align:baseline}
    sub{bottom:-0.25em}sup{top:-0.5em}figure{margin:1em 40px}img{border-style:none}
    code,kbd,pre,samp{font-family:monospace,monospace;font-size:1em}hr{box-sizing:content-box;height:0;overflow:visible}
    button,input,select,textarea,optgroup{font:inherit;margin:0}optgroup{font-weight:bold}
    button,input{overflow:visible}button,select{text-transform:none}
    button,[type=button],[type=reset],[type=submit]{-webkit-appearance:button}
    button::-moz-focus-inner,[type=button]::-moz-focus-inner,[type=reset]::-moz-focus-inner,[type=submit]::-moz-focus-inner{border-style:none;padding:0}
    button:-moz-focusring,[type=button]:-moz-focusring,[type=reset]:-moz-focusring,[type=submit]:-moz-focusring{outline:1px dotted ButtonText}
    fieldset{border:1px solid #c0c0c0;margin:0 2px;padding:.35em .625em .75em}
    legend{color:inherit;display:table;max-width:100%;padding:0;white-space:normal}textarea{overflow:auto}
    [type=checkbox],[type=radio]{padding:0}
    [type=number]::-webkit-inner-spin-button,[type=number]::-webkit-outer-spin-button{height:auto}
    [type=search]{-webkit-appearance:textfield;outline-offset:-2px}
    [type=search]::-webkit-search-decoration{-webkit-appearance:none}
    ::-webkit-file-upload-button{-webkit-appearance:button;font:inherit}
    /* End extract */
    html,body{font-family:Verdana,sans-serif;font-size:15px;line-height:1.5}html{overflow-x:hidden}
    h1{font-size:36px}h2{font-size:30px}h3{font-size:24px}h4{font-size:20px}h5{font-size:18px}h6{font-size:16px}
    .w3-serif{font-family:serif}.w3-sans-serif{font-family:sans-serif}.w3-cursive{font-family:cursive}.w3-monospace{font-family:monospace}
    h1,h2,h3,h4,h5,h6{font-family:"Segoe UI",Arial,sans-serif;font-weight:400;margin:10px 0}.w3-wide{letter-spacing:4px}
    hr{border:0;border-top:1px solid #eee;margin:20px 0}
    .w3-image{max-width:100%;height:auto}img{vertical-align:middle}a{color:inherit}
    .w3-table,.w3-table-all{border-collapse:collapse;border-spacing:0;width:100%;display:table}.w3-table-all{border:1px solid #ccc}
    .w3-bordered tr,.w3-table-all tr{border-bottom:1px solid #ddd}.w3-striped tbody tr:nth-child(even){background-color:#f1f1f1}
    .w3-table-all tr:nth-child(odd){background-color:#fff}.w3-table-all tr:nth-child(even){background-color:#f1f1f1}
    .w3-hoverable tbody tr:hover,.w3-ul.w3-hoverable li:hover{background-color:#ccc}.w3-centered tr th,.w3-centered tr td{text-align:center}
    .w3-table td,.w3-table th,.w3-table-all td,.w3-table-all th{padding:8px 8px;display:table-cell;text-align:left;vertical-align:top}
    .w3-table th:first-child,.w3-table td:first-child,.w3-table-all th:first-child,.w3-table-all td:first-child{padding-left:16px}
    .w3-btn,.w3-button{border:none;display:inline-block;padding:8px 16px;vertical-align:middle;overflow:hidden;text-decoration:none;color:inherit;background-color:inherit;text-align:center;cursor:pointer;white-space:nowrap}
    .w3-btn:hover{box-shadow:0 8px 16px 0 rgba(0,0,0,0.2),0 6px 20px 0 rgba(0,0,0,0.19)}
    .w3-btn,.w3-button{-webkit-touch-callout:none;-webkit-user-select:none;-khtml-user-select:none;-moz-user-select:none;-ms-user-select:none;user-select:none}   
    .w3-disabled,.w3-btn:disabled,.w3-button:disabled{cursor:not-allowed;opacity:0.3}.w3-disabled *,:disabled *{pointer-events:none}
    .w3-btn.w3-disabled:hover,.w3-btn:disabled:hover{box-shadow:none}
    .w3-badge,.w3-tag{background-color:#000;color:#fff;display:inline-block;padding-left:8px;padding-right:8px;text-align:center}.w3-badge{border-radius:50%}
    .w3-ul{list-style-type:none;padding:0;margin:0}.w3-ul li{padding:8px 16px;border-bottom:1px solid #ddd}.w3-ul li:last-child{border-bottom:none}
    .w3-tooltip,.w3-display-container{position:relative}.w3-tooltip .w3-text{display:none}.w3-tooltip:hover .w3-text{display:inline-block}
    .w3-ripple:active{opacity:0.5}.w3-ripple{transition:opacity 0s}
    .w3-input{padding:8px;display:block;border:none;border-bottom:1px solid #ccc;width:100%}
    .w3-select{padding:9px 0;width:100%;border:none;border-bottom:1px solid #ccc}
    .w3-dropdown-click,.w3-dropdown-hover{position:relative;display:inline-block;cursor:pointer}
    .w3-dropdown-hover:hover .w3-dropdown-content{display:block}
    .w3-dropdown-hover:first-child,.w3-dropdown-click:hover{background-color:#ccc;color:#000}
    .w3-dropdown-hover:hover > .w3-button:first-child,.w3-dropdown-click:hover > .w3-button:first-child{background-color:#ccc;color:#000}
    .w3-dropdown-content{cursor:auto;color:#000;background-color:#fff;display:none;position:absolute;min-width:160px;margin:0;padding:0;z-index:1}
    .w3-check,.w3-radio{width:24px;height:24px;position:relative;top:6px}
    .w3-sidebar{height:100%;width:200px;background-color:#fff;position:fixed!important;z-index:1;overflow:auto}
    .w3-bar-block .w3-dropdown-hover,.w3-bar-block .w3-dropdown-click{width:100%}
    .w3-bar-block .w3-dropdown-hover .w3-dropdown-content,.w3-bar-block .w3-dropdown-click .w3-dropdown-content{min-width:100%}
    .w3-bar-block .w3-dropdown-hover .w3-button,.w3-bar-block .w3-dropdown-click .w3-button{width:100%;text-align:left;padding:8px 16px}
    .w3-main,#main{transition:margin-left .4s}
    .w3-modal{z-index:3;display:none;padding-top:100px;position:fixed;left:0;top:0;width:100%;height:100%;overflow:auto;background-color:rgb(0,0,0);background-color:rgba(0,0,0,0.4)}
    .w3-modal-content{margin:auto;background-color:#fff;position:relative;padding:0;outline:0;width:600px}
    .w3-bar{width:100%;overflow:hidden}.w3-center .w3-bar{display:inline-block;width:auto}
    .w3-bar .w3-bar-item{padding:8px 16px;float:left;width:auto;border:none;display:block;outline:0}
    .w3-bar .w3-dropdown-hover,.w3-bar .w3-dropdown-click{position:static;float:left}
    .w3-bar .w3-button{white-space:normal}
    .w3-bar-block .w3-bar-item{width:100%;display:block;padding:8px 16px;text-align:left;border:none;white-space:normal;float:none;outline:0}
    .w3-bar-block.w3-center .w3-bar-item{text-align:center}.w3-block{display:block;width:100%}
    .w3-responsive{display:block;overflow-x:auto}
    .w3-container:after,.w3-container:before,.w3-panel:after,.w3-panel:before,.w3-row:after,.w3-row:before,.w3-row-padding:after,.w3-row-padding:before,
    .w3-cell-row:before,.w3-cell-row:after,.w3-clear:after,.w3-clear:before,.w3-bar:before,.w3-bar:after{content:"";display:table;clear:both}
    .w3-col,.w3-half,.w3-third,.w3-twothird,.w3-threequarter,.w3-quarter{float:left;width:100%}
    .w3-col.s1{width:8.33333%}.w3-col.s2{width:16.66666%}.w3-col.s3{width:24.99999%}.w3-col.s4{width:33.33333%}
    .w3-col.s5{width:41.66666%}.w3-col.s6{width:49.99999%}.w3-col.s7{width:58.33333%}.w3-col.s8{width:66.66666%}
    .w3-col.s9{width:74.99999%}.w3-col.s10{width:83.33333%}.w3-col.s11{width:91.66666%}.w3-col.s12{width:99.99999%}
    @media (min-width:601px){.w3-col.m1{width:8.33333%}.w3-col.m2{width:16.66666%}.w3-col.m3,.w3-quarter{width:24.99999%}.w3-col.m4,.w3-third{width:33.33333%}
    .w3-col.m5{width:41.66666%}.w3-col.m6,.w3-half{width:49.99999%}.w3-col.m7{width:58.33333%}.w3-col.m8,.w3-twothird{width:66.66666%}
    .w3-col.m9,.w3-threequarter{width:74.99999%}.w3-col.m10{width:83.33333%}.w3-col.m11{width:91.66666%}.w3-col.m12{width:99.99999%}}
    @media (min-width:993px){.w3-col.l1{width:8.33333%}.w3-col.l2{width:16.66666%}.w3-col.l3{width:24.99999%}.w3-col.l4{width:33.33333%}
    .w3-col.l5{width:41.66666%}.w3-col.l6{width:49.99999%}.w3-col.l7{width:58.33333%}.w3-col.l8{width:66.66666%}
    .w3-col.l9{width:74.99999%}.w3-col.l10{width:83.33333%}.w3-col.l11{width:91.66666%}.w3-col.l12{width:99.99999%}}
    .w3-rest{overflow:hidden}.w3-stretch{margin-left:-16px;margin-right:-16px}
    .w3-content,.w3-auto{margin-left:auto;margin-right:auto}.w3-content{max-width:980px}.w3-auto{max-width:1140px}
    .w3-cell-row{display:table;width:100%}.w3-cell{display:table-cell}
    .w3-cell-top{vertical-align:top}.w3-cell-middle{vertical-align:middle}.w3-cell-bottom{vertical-align:bottom}
    .w3-hide{display:none!important}.w3-show-block,.w3-show{display:block!important}.w3-show-inline-block{display:inline-block!important}
    @media (max-width:1205px){.w3-auto{max-width:95%}}
    @media (max-width:600px){.w3-modal-content{margin:0 10px;width:auto!important}.w3-modal{padding-top:30px}
    .w3-dropdown-hover.w3-mobile .w3-dropdown-content,.w3-dropdown-click.w3-mobile .w3-dropdown-content{position:relative}  
    .w3-hide-small{display:none!important}.w3-mobile{display:block;width:100%!important}.w3-bar-item.w3-mobile,.w3-dropdown-hover.w3-mobile,.w3-dropdown-click.w3-mobile{text-align:center}
    .w3-dropdown-hover.w3-mobile,.w3-dropdown-hover.w3-mobile .w3-btn,.w3-dropdown-hover.w3-mobile .w3-button,.w3-dropdown-click.w3-mobile,.w3-dropdown-click.w3-mobile .w3-btn,.w3-dropdown-click.w3-mobile .w3-button{width:100%}}
    @media (max-width:768px){.w3-modal-content{width:500px}.w3-modal{padding-top:50px}}
    @media (min-width:993px){.w3-modal-content{width:900px}.w3-hide-large{display:none!important}.w3-sidebar.w3-collapse{display:block!important}}
    @media (max-width:992px) and (min-width:601px){.w3-hide-medium{display:none!important}}
    @media (max-width:992px){.w3-sidebar.w3-collapse{display:none}.w3-main{margin-left:0!important;margin-right:0!important}.w3-auto{max-width:100%}}
    .w3-top,.w3-bottom{position:fixed;width:100%;z-index:1}.w3-top{top:0}.w3-bottom{bottom:0}
    .w3-overlay{position:fixed;display:none;width:100%;height:100%;top:0;left:0;right:0;bottom:0;background-color:rgba(0,0,0,0.5);z-index:2}
    .w3-display-topleft{position:absolute;left:0;top:0}.w3-display-topright{position:absolute;right:0;top:0}
    .w3-display-bottomleft{position:absolute;left:0;bottom:0}.w3-display-bottomright{position:absolute;right:0;bottom:0}
    .w3-display-middle{position:absolute;top:50%;left:50%;transform:translate(-50%,-50%);-ms-transform:translate(-50%,-50%)}
    .w3-display-left{position:absolute;top:50%;left:0%;transform:translate(0%,-50%);-ms-transform:translate(-0%,-50%)}
    .w3-display-right{position:absolute;top:50%;right:0%;transform:translate(0%,-50%);-ms-transform:translate(0%,-50%)}
    .w3-display-topmiddle{position:absolute;left:50%;top:0;transform:translate(-50%,0%);-ms-transform:translate(-50%,0%)}
    .w3-display-bottommiddle{position:absolute;left:50%;bottom:0;transform:translate(-50%,0%);-ms-transform:translate(-50%,0%)}
    .w3-display-container:hover .w3-display-hover{display:block}.w3-display-container:hover span.w3-display-hover{display:inline-block}.w3-display-hover{display:none}
    .w3-display-position{position:absolute}
    .w3-circle{border-radius:50%}
    .w3-round-small{border-radius:2px}.w3-round,.w3-round-medium{border-radius:4px}.w3-round-large{border-radius:8px}.w3-round-xlarge{border-radius:16px}.w3-round-xxlarge{border-radius:32px}
    .w3-row-padding,.w3-row-padding>.w3-half,.w3-row-padding>.w3-third,.w3-row-padding>.w3-twothird,.w3-row-padding>.w3-threequarter,.w3-row-padding>.w3-quarter,.w3-row-padding>.w3-col{padding:0 8px}
    .w3-container,.w3-panel{padding:0.01em 16px}.w3-panel{margin-top:16px;margin-bottom:16px}
    .w3-code,.w3-codespan{font-family:Consolas,"courier new";font-size:16px}
    .w3-code{width:auto;background-color:#fff;padding:8px 12px;border-left:4px solid #4CAF50;word-wrap:break-word}
    .w3-codespan{color:crimson;background-color:#f1f1f1;padding-left:4px;padding-right:4px;font-size:110%}
    .w3-card,.w3-card-2{box-shadow:0 2px 5px 0 rgba(0,0,0,0.16),0 2px 10px 0 rgba(0,0,0,0.12)}
    .w3-card-4,.w3-hover-shadow:hover{box-shadow:0 4px 10px 0 rgba(0,0,0,0.2),0 4px 20px 0 rgba(0,0,0,0.19)}
    .w3-spin{animation:w3-spin 2s infinite linear}@keyframes w3-spin{0%{transform:rotate(0deg)}100%{transform:rotate(359deg)}}
    .w3-animate-fading{animation:fading 10s infinite}@keyframes fading{0%{opacity:0}50%{opacity:1}100%{opacity:0}}
    .w3-animate-opacity{animation:opac 0.8s}@keyframes opac{from{opacity:0} to{opacity:1}}
    .w3-animate-top{position:relative;animation:animatetop 0.4s}@keyframes animatetop{from{top:-300px;opacity:0} to{top:0;opacity:1}}
    .w3-animate-left{position:relative;animation:animateleft 0.4s}@keyframes animateleft{from{left:-300px;opacity:0} to{left:0;opacity:1}}
    .w3-animate-right{position:relative;animation:animateright 0.4s}@keyframes animateright{from{right:-300px;opacity:0} to{right:0;opacity:1}}
    .w3-animate-bottom{position:relative;animation:animatebottom 0.4s}@keyframes animatebottom{from{bottom:-300px;opacity:0} to{bottom:0;opacity:1}}
    .w3-animate-zoom {animation:animatezoom 0.6s}@keyframes animatezoom{from{transform:scale(0)} to{transform:scale(1)}}
    .w3-animate-input{transition:width 0.4s ease-in-out}.w3-animate-input:focus{width:100%!important}
    .w3-opacity,.w3-hover-opacity:hover{opacity:0.60}.w3-opacity-off,.w3-hover-opacity-off:hover{opacity:1}
    .w3-opacity-max{opacity:0.25}.w3-opacity-min{opacity:0.75}
    .w3-greyscale-max,.w3-grayscale-max,.w3-hover-greyscale:hover,.w3-hover-grayscale:hover{filter:grayscale(100%)}
    .w3-greyscale,.w3-grayscale{filter:grayscale(75%)}.w3-greyscale-min,.w3-grayscale-min{filter:grayscale(50%)}
    .w3-sepia{filter:sepia(75%)}.w3-sepia-max,.w3-hover-sepia:hover{filter:sepia(100%)}.w3-sepia-min{filter:sepia(50%)}
    .w3-tiny{font-size:10px!important}.w3-small{font-size:12px!important}.w3-medium{font-size:15px!important}.w3-large{font-size:18px!important}
    .w3-xlarge{font-size:24px!important}.w3-xxlarge{font-size:36px!important}.w3-xxxlarge{font-size:48px!important}.w3-jumbo{font-size:64px!important}
    .w3-left-align{text-align:left!important}.w3-right-align{text-align:right!important}.w3-justify{text-align:justify!important}.w3-center{text-align:center!important}
    .w3-border-0{border:0!important}.w3-border{border:1px solid #ccc!important}
    .w3-border-top{border-top:1px solid #ccc!important}.w3-border-bottom{border-bottom:1px solid #ccc!important}
    .w3-border-left{border-left:1px solid #ccc!important}.w3-border-right{border-right:1px solid #ccc!important}
    .w3-topbar{border-top:6px solid #ccc!important}.w3-bottombar{border-bottom:6px solid #ccc!important}
    .w3-leftbar{border-left:6px solid #ccc!important}.w3-rightbar{border-right:6px solid #ccc!important}
    .w3-section,.w3-code{margin-top:16px!important;margin-bottom:16px!important}
    .w3-margin{margin:16px!important}.w3-margin-top{margin-top:16px!important}.w3-margin-bottom{margin-bottom:16px!important}
    .w3-margin-left{margin-left:16px!important}.w3-margin-right{margin-right:16px!important}
    .w3-padding-small{padding:4px 8px!important}.w3-padding{padding:8px 16px!important}.w3-padding-large{padding:12px 24px!important}
    .w3-padding-16{padding-top:16px!important;padding-bottom:16px!important}.w3-padding-24{padding-top:24px!important;padding-bottom:24px!important}
    .w3-padding-32{padding-top:32px!important;padding-bottom:32px!important}.w3-padding-48{padding-top:48px!important;padding-bottom:48px!important}
    .w3-padding-64{padding-top:64px!important;padding-bottom:64px!important}
    .w3-padding-top-64{padding-top:64px!important}.w3-padding-top-48{padding-top:48px!important}
    .w3-padding-top-32{padding-top:32px!important}.w3-padding-top-24{padding-top:24px!important}
    .w3-left{float:left!important}.w3-right{float:right!important}
    .w3-button:hover{color:#000!important;background-color:#ccc!important}
    .w3-transparent,.w3-hover-none:hover{background-color:transparent!important}
    .w3-hover-none:hover{box-shadow:none!important}
    /* Colors */
    .w3-amber,.w3-hover-amber:hover{color:#000!important;background-color:#ffc107!important}
    .w3-aqua,.w3-hover-aqua:hover{color:#000!important;background-color:#00ffff!important}
    .w3-blue,.w3-hover-blue:hover{color:#fff!important;background-color:#2196F3!important}
    .w3-light-blue,.w3-hover-light-blue:hover{color:#000!important;background-color:#87CEEB!important}
    .w3-brown,.w3-hover-brown:hover{color:#fff!important;background-color:#795548!important}
    .w3-cyan,.w3-hover-cyan:hover{color:#000!important;background-color:#00bcd4!important}
    .w3-blue-grey,.w3-hover-blue-grey:hover,.w3-blue-gray,.w3-hover-blue-gray:hover{color:#fff!important;background-color:#607d8b!important}
    .w3-green,.w3-hover-green:hover{color:#fff!important;background-color:#4CAF50!important}
    .w3-light-green,.w3-hover-light-green:hover{color:#000!important;background-color:#8bc34a!important}
    .w3-indigo,.w3-hover-indigo:hover{color:#fff!important;background-color:#3f51b5!important}
    .w3-khaki,.w3-hover-khaki:hover{color:#000!important;background-color:#f0e68c!important}
    .w3-lime,.w3-hover-lime:hover{color:#000!important;background-color:#cddc39!important}
    .w3-orange,.w3-hover-orange:hover{color:#000!important;background-color:#ff9800!important}
    .w3-deep-orange,.w3-hover-deep-orange:hover{color:#fff!important;background-color:#ff5722!important}
    .w3-pink,.w3-hover-pink:hover{color:#fff!important;background-color:#e91e63!important}
    .w3-purple,.w3-hover-purple:hover{color:#fff!important;background-color:#9c27b0!important}
    .w3-deep-purple,.w3-hover-deep-purple:hover{color:#fff!important;background-color:#673ab7!important}
    .w3-red,.w3-hover-red:hover{color:#fff!important;background-color:#f44336!important}
    .w3-sand,.w3-hover-sand:hover{color:#000!important;background-color:#fdf5e6!important}
    .w3-teal,.w3-hover-teal:hover{color:#fff!important;background-color:#009688!important}
    .w3-yellow,.w3-hover-yellow:hover{color:#000!important;background-color:#ffeb3b!important}
    .w3-white,.w3-hover-white:hover{color:#000!important;background-color:#fff!important}
    .w3-black,.w3-hover-black:hover{color:#fff!important;background-color:#000!important}
    .w3-grey,.w3-hover-grey:hover,.w3-gray,.w3-hover-gray:hover{color:#000!important;background-color:#9e9e9e!important}
    .w3-light-grey,.w3-hover-light-grey:hover,.w3-light-gray,.w3-hover-light-gray:hover{color:#000!important;background-color:#f1f1f1!important}
    .w3-dark-grey,.w3-hover-dark-grey:hover,.w3-dark-gray,.w3-hover-dark-gray:hover{color:#fff!important;background-color:#616161!important}
    .w3-pale-red,.w3-hover-pale-red:hover{color:#000!important;background-color:#ffdddd!important}
    .w3-pale-green,.w3-hover-pale-green:hover{color:#000!important;background-color:#ddffdd!important}
    .w3-pale-yellow,.w3-hover-pale-yellow:hover{color:#000!important;background-color:#ffffcc!important}
    .w3-pale-blue,.w3-hover-pale-blue:hover{color:#000!important;background-color:#ddffff!important}
    .w3-text-amber,.w3-hover-text-amber:hover{color:#ffc107!important}
    .w3-text-aqua,.w3-hover-text-aqua:hover{color:#00ffff!important}
    .w3-text-blue,.w3-hover-text-blue:hover{color:#2196F3!important}
    .w3-text-light-blue,.w3-hover-text-light-blue:hover{color:#87CEEB!important}
    .w3-text-brown,.w3-hover-text-brown:hover{color:#795548!important}
    .w3-text-cyan,.w3-hover-text-cyan:hover{color:#00bcd4!important}
    .w3-text-blue-grey,.w3-hover-text-blue-grey:hover,.w3-text-blue-gray,.w3-hover-text-blue-gray:hover{color:#607d8b!important}
    .w3-text-green,.w3-hover-text-green:hover{color:#4CAF50!important}
    .w3-text-light-green,.w3-hover-text-light-green:hover{color:#8bc34a!important}
    .w3-text-indigo,.w3-hover-text-indigo:hover{color:#3f51b5!important}
    .w3-text-khaki,.w3-hover-text-khaki:hover{color:#b4aa50!important}
    .w3-text-lime,.w3-hover-text-lime:hover{color:#cddc39!important}
    .w3-text-orange,.w3-hover-text-orange:hover{color:#ff9800!important}
    .w3-text-deep-orange,.w3-hover-text-deep-orange:hover{color:#ff5722!important}
    .w3-text-pink,.w3-hover-text-pink:hover{color:#e91e63!important}
    .w3-text-purple,.w3-hover-text-purple:hover{color:#9c27b0!important}
    .w3-text-deep-purple,.w3-hover-text-deep-purple:hover{color:#673ab7!important}
    .w3-text-red,.w3-hover-text-red:hover{color:#f44336!important}
    .w3-text-sand,.w3-hover-text-sand:hover{color:#fdf5e6!important}
    .w3-text-teal,.w3-hover-text-teal:hover{color:#009688!important}
    .w3-text-yellow,.w3-hover-text-yellow:hover{color:#d2be0e!important}
    .w3-text-white,.w3-hover-text-white:hover{color:#fff!important}
    .w3-text-black,.w3-hover-text-black:hover{color:#000!important}
    .w3-text-grey,.w3-hover-text-grey:hover,.w3-text-gray,.w3-hover-text-gray:hover{color:#757575!important}
    .w3-text-light-grey,.w3-hover-text-light-grey:hover,.w3-text-light-gray,.w3-hover-text-light-gray:hover{color:#f1f1f1!important}
    .w3-text-dark-grey,.w3-hover-text-dark-grey:hover,.w3-text-dark-gray,.w3-hover-text-dark-gray:hover{color:#3a3a3a!important}
    .w3-border-amber,.w3-hover-border-amber:hover{border-color:#ffc107!important}
    .w3-border-aqua,.w3-hover-border-aqua:hover{border-color:#00ffff!important}
    .w3-border-blue,.w3-hover-border-blue:hover{border-color:#2196F3!important}
    .w3-border-light-blue,.w3-hover-border-light-blue:hover{border-color:#87CEEB!important}
    .w3-border-brown,.w3-hover-border-brown:hover{border-color:#795548!important}
    .w3-border-cyan,.w3-hover-border-cyan:hover{border-color:#00bcd4!important}
    .w3-border-blue-grey,.w3-hover-border-blue-grey:hover,.w3-border-blue-gray,.w3-hover-border-blue-gray:hover{border-color:#607d8b!important}
    .w3-border-green,.w3-hover-border-green:hover{border-color:#4CAF50!important}
    .w3-border-light-green,.w3-hover-border-light-green:hover{border-color:#8bc34a!important}
    .w3-border-indigo,.w3-hover-border-indigo:hover{border-color:#3f51b5!important}
    .w3-border-khaki,.w3-hover-border-khaki:hover{border-color:#f0e68c!important}
    .w3-border-lime,.w3-hover-border-lime:hover{border-color:#cddc39!important}
    .w3-border-orange,.w3-hover-border-orange:hover{border-color:#ff9800!important}
    .w3-border-deep-orange,.w3-hover-border-deep-orange:hover{border-color:#ff5722!important}
    .w3-border-pink,.w3-hover-border-pink:hover{border-color:#e91e63!important}
    .w3-border-purple,.w3-hover-border-purple:hover{border-color:#9c27b0!important}
    .w3-border-deep-purple,.w3-hover-border-deep-purple:hover{border-color:#673ab7!important}
    .w3-border-red,.w3-hover-border-red:hover{border-color:#f44336!important}
    .w3-border-sand,.w3-hover-border-sand:hover{border-color:#fdf5e6!important}
    .w3-border-teal,.w3-hover-border-teal:hover{border-color:#009688!important}
    .w3-border-yellow,.w3-hover-border-yellow:hover{border-color:#ffeb3b!important}
    .w3-border-white,.w3-hover-border-white:hover{border-color:#fff!important}
    .w3-border-black,.w3-hover-border-black:hover{border-color:#000!important}
    .w3-border-grey,.w3-hover-border-grey:hover,.w3-border-gray,.w3-hover-border-gray:hover{border-color:#9e9e9e!important}
    .w3-border-light-grey,.w3-hover-border-light-grey:hover,.w3-border-light-gray,.w3-hover-border-light-gray:hover{border-color:#f1f1f1!important}
    .w3-border-dark-grey,.w3-hover-border-dark-grey:hover,.w3-border-dark-gray,.w3-hover-border-dark-gray:hover{border-color:#616161!important}
    .w3-border-pale-red,.w3-hover-border-pale-red:hover{border-color:#ffe7e7!important}.w3-border-pale-green,.w3-hover-border-pale-green:hover{border-color:#e7ffe7!important}
    .w3-border-pale-yellow,.w3-hover-border-pale-yellow:hover{border-color:#ffffcc!important}.w3-border-pale-blue,.w3-hover-border-pale-blue:hover{border-color:#e7ffff!important}
    </style>
    <style>
    /* Remove margins and padding from the list */
    ul {
      margin: 0;
      padding: 0;
    }

    /* Style the list items */
    ul li {
      cursor: pointer;
      position: relative;
      padding: 12px 8px 12px 40px;
      list-style-type: none;
      background: #eee;
      font-family:'Arial';
      font-size: 22px;
      transition: 0.0s;
      height: 88px;

      /* make the list items unselectable */
      -webkit-user-select: none;
      -moz-user-select: none;
      -ms-user-select: none;
      user-select: none;
    }

    /* Set all odd list items to a different color (zebra-stripes) */
    ul li:nth-child(odd) {
      background: #f9f9f9;
    }

    /* Darker background-color on hover */
    ul li:hover {
      background: #ddd;
    }

    .timer {
      position: absolute;
      left: 24px;
      top: 35px;
      padding: 12px 16px 12px 16px;
      font-size: 16px;
    }

    /* Style the close button */
    .close {
      position: absolute;
      right: 0;
      top: 16px;
      padding: 12px 16px 12px 16px;
    }

    .close:hover {
      background-color: #D22F30;
      color: white;
    }

    /* Style the header */
    .header {
      margin: 0;
      background-color: #D22F30;
      padding: 30px 10px;
      color: white;
      text-align: center;
      font-size: 48px;
      font-family: Arial;
      text-decoration-line: underline;
    }

    /* Style the input box */
    .inputBox {
      display: inline-block;
      border: none;
      padding-left: 12px;
      width: 70%;
      font-family:'Arial';
      font-size: 36px;
      vertical-align: center;
    }

    /* Style the "Add" button */
    .addBtn {
      width: 20%;
      height: 56px;
      background: #09a009;
      color: #ffffff;
      text-align: center;
      float: right;
      cursor: pointer;
      transition: 0.3s;
      padding: 0px;
      font-family:'Arial';
      font-size: 24px;
    }

    .streakImageL {
      position: absolute;
      height: 90px;
      right: 69%;
    }

    .streakImageR {
      position: absolute;
      height: 90px;
      left: 69%;
    }

    .streakText {
      font-family:'Arial';
      font-weight: 600;
      color: white;
      background-color: #D22F30;
      text-align: center;
      font-size: 63px;
      margin-top: 0px;
      margin-bottom: 0px;
    }

    .reOrder {
      position: absolute;
      top: 27px;
      left: 10px;
      height: 15px;
      /* Prevent scrolling down the page when we want to just reorder the list */
      touch-action: none;
    }
    </style>
  </head>
  <body>
    <!-- Place the title of the Webpage -->
    <h2 class="header">Today's To-Do List</h2>

    <!-- Parent div forces all on the same line-->
    <div id="parent" style="white-space: nowrap; overflow-x: auto;">
      <!-- Place the streak image -->
      <img src="data:image/jpeg;base64,/9j/4AAQSkZJRgABAQEBLAEsAAD/4QBWRXhpZgAATU0AKgAAAAgABAEaAAUAAAABAAAAPgEbAAUAAAABAAAARgEoAAMAAAABAAIAAAITAAMAAAABAAEAAAAAAAAAAAEsAAAAAQAAASwAAAAB/+0ALFBob3Rvc2hvcCAzLjAAOEJJTQQEAAAAAAAPHAFaAAMbJUccAQAAAgAEAP/hDIFodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvADw/eHBhY2tldCBiZWdpbj0n77u/JyBpZD0nVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkJz8+Cjx4OnhtcG1ldGEgeG1sbnM6eD0nYWRvYmU6bnM6bWV0YS8nIHg6eG1wdGs9J0ltYWdlOjpFeGlmVG9vbCAxMS44OCc+CjxyZGY6UkRGIHhtbG5zOnJkZj0naHR0cDovL3d3dy53My5vcmcvMTk5OS8wMi8yMi1yZGYtc3ludGF4LW5zIyc+CgogPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9JycKICB4bWxuczp0aWZmPSdodHRwOi8vbnMuYWRvYmUuY29tL3RpZmYvMS4wLyc+CiAgPHRpZmY6UmVzb2x1dGlvblVuaXQ+MjwvdGlmZjpSZXNvbHV0aW9uVW5pdD4KICA8dGlmZjpYUmVzb2x1dGlvbj4zMDAvMTwvdGlmZjpYUmVzb2x1dGlvbj4KICA8dGlmZjpZUmVzb2x1dGlvbj4zMDAvMTwvdGlmZjpZUmVzb2x1dGlvbj4KIDwvcmRmOkRlc2NyaXB0aW9uPgoKIDxyZGY6RGVzY3JpcHRpb24gcmRmOmFib3V0PScnCiAgeG1sbnM6eG1wTU09J2h0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9tbS8nPgogIDx4bXBNTTpEb2N1bWVudElEPmFkb2JlOmRvY2lkOnN0b2NrOjdhODlkMjI1LTJhMTktNDBjMi05ZmJiLWRkMjFkODU0YTUxNTwveG1wTU06RG9jdW1lbnRJRD4KICA8eG1wTU06SW5zdGFuY2VJRD54bXAuaWlkOjI5YWEzNDY2LTJiN2MtNDQ5Zi04NDBkLWQwODk0YWE1Mzk4YzwveG1wTU06SW5zdGFuY2VJRD4KIDwvcmRmOkRlc2NyaXB0aW9uPgo8L3JkZjpSREY+CjwveDp4bXBtZXRhPgogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAo8P3hwYWNrZXQgZW5kPSd3Jz8+/9sAQwAFAwQEBAMFBAQEBQUFBgcMCAcHBwcPCwsJDBEPEhIRDxERExYcFxMUGhURERghGBodHR8fHxMXIiQiHiQcHh8e/9sAQwEFBQUHBgcOCAgOHhQRFB4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4e/8AAEQgBaAFoAwERAAIRAQMRAf/EAB0AAQACAgMBAQAAAAAAAAAAAAAGCAUHAQMECQL/xABKEAABAwMBBQQFBwoDBwUBAAABAAIDBAURBgcSITFRCBNBYSJxgZGhFDJCUmKxwQkVIzNj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tjubZat5afZnC8TeuVc6pZVrLsHa/Bapj4QwJoaMuLjTRbx5kNwSvO/V1Xpw1qfyw4FBRj/ho/cm/V1Pstn/ABh2Mp4GfMhjb6mhUmqZe6bVFPKIdqouCAgICAgICAgICAgICAgICAgHmUUgRUQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQDzKKQIqICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIB5lFIEVEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEA8yikCKiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAeZRSBFRAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAPMopAiogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgHmUUgRUQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQDzKKQIqICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIB5lFIEVEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEH//Z" class="streakImageL">
      <img src="data:image/jpeg;base64,/9j/4AAQSkZJRgABAQEBLAEsAAD/4QBWRXhpZgAATU0AKgAAAAgABAEaAAUAAAABAAAAPgEbAAUAAAABAAAARgEoAAMAAAABAAIAAAITAAMAAAABAAEAAAAAAAAAAAEsAAAAAQAAASwAAAAB/+0ALFBob3Rvc2hvcCAzLjAAOEJJTQQEAAAAAAAPHAFaAAMbJUccAQAAAgAEAP/hDIFodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvADw/eHBhY2tldCBiZWdpbj0n77u/JyBpZD0nVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkJz8+Cjx4OnhtcG1ldGEgeG1sbnM6eD0nYWRvYmU6bnM6bWV0YS8nIHg6eG1wdGs9J0ltYWdlOjpFeGlmVG9vbCAxMS44OCc+CjxyZGY6UkRGIHhtbG5zOnJkZj0naHR0cDovL3d3dy53My5vcmcvMTk5OS8wMi8yMi1yZGYtc3ludGF4LW5zIyc+CgogPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9JycKICB4bWxuczp0aWZmPSdodHRwOi8vbnMuYWRvYmUuY29tL3RpZmYvMS4wLyc+CiAgPHRpZmY6UmVzb2x1dGlvblVuaXQ+MjwvdGlmZjpSZXNvbHV0aW9uVW5pdD4KICA8dGlmZjpYUmVzb2x1dGlvbj4zMDAvMTwvdGlmZjpYUmVzb2x1dGlvbj4KICA8dGlmZjpZUmVzb2x1dGlvbj4zMDAvMTwvdGlmZjpZUmVzb2x1dGlvbj4KIDwvcmRmOkRlc2NyaXB0aW9uPgoKIDxyZGY6RGVzY3JpcHRpb24gcmRmOmFib3V0PScnCiAgeG1sbnM6eG1wTU09J2h0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9tbS8nPgogIDx4bXBNTTpEb2N1bWVudElEPmFkb2JlOmRvY2lkOnN0b2NrOjdhODlkMjI1LTJhMTktNDBjMi05ZmJiLWRkMjFkODU0YTUxNTwveG1wTU06RG9jdW1lbnRJRD4KICA8eG1wTU06SW5zdGFuY2VJRD54bXAuaWlkOjI5YWEzNDY2LTJiN2MtNDQ5Zi04NDBkLWQwODk0YWE1Mzk4YzwveG1wTU06SW5zdGFuY2VJRD4KIDwvcmRmOkRlc2NyaXB0aW9uPgo8L3JkZjpSREY+CjwveDp4bXBtZXRhPgogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAo8P3hwYWNrZXQgZW5kPSd3Jz8+/9sAQwAFAwQEBAMFBAQEBQUFBgcMCAcHBwcPCwsJDBEPEhIRDxERExYcFxMUGhURERghGBodHR8fHxMXIiQiHiQcHh8e/9sAQwEFBQUHBgcOCAgOHhQRFB4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4e/8AAEQgBaAFoAwERAAIRAQMRAf/EAB0AAQACAgMBAQAAAAAAAAAAAAAGCAUHAQMECQL/xABKEAABAwMBBQQFBwoDBwUBAAABAAIDBAURBgcSITFRCBNBYSJxgZGhFDJCUmKxwQkVIzNj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tjubZat5afZnC8TeuVc6pZVrLsHa/Bapj4QwJoaMuLjTRbx5kNwSvO/V1Xpw1qfyw4FBRj/ho/cm/V1Pstn/ABh2Mp4GfMhjb6mhUmqZe6bVFPKIdqouCAgICAgICAgICAgICAgICAgHmUUgRUQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQDzKKQIqICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIB5lFIEVEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEA8yikCKiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAeZRSBFRAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAPMopAiogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgHmUUgRUQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQDzKKQIqICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIB5lFIEVEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEH//Z" class="streakImageR">
      <!-- The following line would be easier if we have internet, but we don't! -->
      <!-- <img src="https://t4.ftcdn.net/jpg/03/63/57/21/360_F_363572186_25fxXDyWgNHeQtyPnb9YP9T6DVv7UP1N.jpg" class="streakImageL"> -->
      <!-- <img src="https://t4.ftcdn.net/jpg/03/63/57/21/360_F_363572186_25fxXDyWgNHeQtyPnb9YP9T6DVv7UP1N.jpg" class="streakImageR"> -->
      <!-- Place the number for the streak -->
      <h1 id="streakText" class="streakText">0</h1>
    </div>

    <!-- Parent div forces all on the same line-->
    <div id="parent" style="white-space: nowrap; overflow-x: auto;">
      <!-- Place the add button to add the element to the list -->
      <button onclick="addBtn()" class="addBtn">Add</button>
      <!-- Place the input box for entering a new task -->
      <input class="inputBox" type="text" id="myInput" placeholder="Enter a New Task...">
    </div>

    <!-- Show the list elements -->
    <ul id="list">
      <!-- <li draggable="true">List Item</li> -->
    </ul>

    <!-- Webpage script -->
    <script>
var dragging = null;

var lastTouchX, lastTouchY;

console.log("Website loaded!");
// Tell the ESP we want to send the list from the beginning.
resetListCounter();
// Get the contents of the list, sending a request every 100ms.
var myTimer = setInterval(getListItem, 100);
// Check if the list item was completed. (Do this in the future AFTER
// the webpage has been initialized.
var hardwareCompleted = null;
// Stores the number of times the ESP did not repsond.
var failureCounter = 0;
// Required so the main XHTTP function knows whether or not a
// response was received, and can either reset or increment
// the failureCounter variable.
var failed = false;
// Store the global due time, gets updated every time a checkFinished
// request is processed. Use this to change the dates for new items.
var newListItemDueTime = 17;

var touchActive = false;

document.addEventListener('touchmove', function(event)
{
  var target = getLI(event.target);
  if (touchActive == false)
  {
    dragging = target;
    touchActive = true;
  }
  lastTouchX = event.touches[0].clientX;
  lastTouchY = event.touches[0].clientY;
  // Prevent reordering list items if we are not on the reorder icon.
  if (event.target.getAttribute("class") != "reOrder")
  {
    return;
  }
  var actualTarget = getLI(document.elementFromPoint(lastTouchX, lastTouchY));
  var bounding = actualTarget.getBoundingClientRect();
  var offset = bounding.y + (bounding.height / 2);

  var list = document.getElementsByTagName("LI");
  // Remove borders on the other lines where we are not currently dragging to.
  for (var i = 0; i < list.length; i++)
  {
    list[i].style['border-bottom'] = '';
    list[i].style['border-top'] = '';
  }
  if (lastTouchY - offset > 0) {
    actualTarget.style['border-bottom'] = 'solid 2px black';
    actualTarget.style['border-top'] = '';
  } else {
    actualTarget.style['border-top'] = 'solid 2px black';
    actualTarget.style['border-bottom'] = '';
  }
});

document.addEventListener('touchend', function(event)
{
  var target = getLI(event.target);
  var actualTarget = getLI(document.elementFromPoint(lastTouchX, lastTouchY));
  // Store a variable that gets set to true only if a border exists
  // on one of the list items (i.e. we reordered the list).
  var reOrdered = false;
  
  if (actualTarget.style['border-bottom'] !== '') {
    actualTarget.style['border-bottom'] = '';
    target.parentNode.insertBefore(dragging, actualTarget.nextSibling);
    reOrdered = true;
  }
  else if (actualTarget.style['border-top'] !== '') {
    actualTarget.style['border-top'] = '';
    target.parentNode.insertBefore(dragging, actualTarget);
    reOrdered = true;
  }
  touchActive = false;
  // Send the updated list order only if we reordered the list
  // (prevents scrolling action from triggering this).
  if (reOrdered == true)
  {
    sendUpdatedListOrder();
  }
});

document.addEventListener('dragstart', function(event)
{
  var target = getLI(event.target);
  dragging = target;
  event.dataTransfer.setData('text/plain', null);
  event.dataTransfer.setDragImage(self.dragging, 0, 0);
});

document.addEventListener('dragover', function(event)
{
  event.preventDefault();
  var target = getLI(event.target);
  var bounding = target.getBoundingClientRect();
  var offset = bounding.y + (bounding.height / 2);
  if (event.clientY - offset > 0)
  {
    target.style['border-bottom'] = 'solid 2px black';
    target.style['border-top'] = '';
  }
  else
  {
    target.style['border-top'] = 'solid 2px black';
    target.style['border-bottom'] = '';
  }
}); 

document.addEventListener('dragleave', function(event)
{
  var target = getLI(event.target);
  target.style['border-bottom'] = '';
  target.style['border-top'] = '';
});

document.addEventListener('drop', function(event)
{
  event.preventDefault();
  var target = getLI(event.target);
  if (target.style['border-bottom'] !== '')
  {
    console.log("before next");
    target.style['border-bottom'] = '';
    target.parentNode.insertBefore(dragging, target.nextSibling);
  }
  else if (target.style['border-top'] !== '')
  {
    console.log("before current");
    target.style['border-top'] = '';
    target.parentNode.insertBefore(dragging, target);
  }
  sendUpdatedListOrder();
});

const arrayColumn = (arr, n) => arr.map(x => x[n]);
function nextChar(c)
{
  return String.fromCharCode(c.charCodeAt(0) + 1);
}

function sendUpdatedListOrder()
{
  var list = document.getElementsByTagName("li");
  var itemNumberArray = new Array(list.length);
  var itemIdxIter = 1;
  for (var i = 0; i < list.length; i++)
  {
    itemNumberArray[i] = new Array(2);
    itemNumberArray[i][0] = "itemName" + itemIdxIter.toString();
    itemNumberArray[i][1] = list[i].getAttribute("listItemName");
    itemIdxIter++;
  }
  // Send the updated list order to the ESP.
  sendData("reOrderItem", arrayColumn(itemNumberArray, 0), arrayColumn(itemNumberArray, 1));
  // Re-order the list since we just changed the order by dragging an item.
  // This ensures the webpage and the ESP are in sync so the next time an
  // item is dragged, the ESP reorders the correct one in its own array.
  reOrderListItemNumbers();
  console.log("new");
  for (var i = 0; i < list.length; i++)
  {
    console.log(list[i].getAttribute("listItemNumber"));
  }
}

function resetListCounter()
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200)
    {
      // No response expected from this function.
    }
  };
  xhttp.open("GET", "resetListCounter", true); // true for asynchronous
  xhttp.send();
}

function getListItem()
{
  var xhttp = new XMLHttpRequest();
  xhttp.addEventListener('error', function(e)
  {
    failed = true;
  });
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200)
    {
      // Get the response from the ESP.
      var responseStr = this.responseText;
      if (responseStr == "end")
      {
        // Reached the end of the list.
        clearInterval(myTimer);
        // We need to start another interval now that the initial
        // list syncing is complete. Check for if the task complete
        // button was pressed every 2.5 seconds.
        // Make sure the interval is only set once!
        if (hardwareCompleted == null)
        {
          hardwareCompleted = setInterval(checkCompleted, 2500);
        }
      }
      else
      {
        var toParse = new URL(responseStr);
        var listItemNumber = toParse.searchParams.get("num");
        var listItemName = toParse.searchParams.get("name");
        var dueTime = toParse.searchParams.get("dueTime");
        newElement(listItemNumber, listItemName, dueTime, "999");
        // Get the next list item. Stop recursion.
      }
    }
  };
  xhttp.open("GET", "sendListItem", true); // true for asynchronous
  xhttp.send();
  if (failed == true)
  {
    failureCounter++;
    // Stop calling this function if the failure rate is too high
    // (the ESP is not connected).
    if (failureCounter == 5)
    {
      clearInterval(myTimer);
    }
    failed = false;
  }
  else
  {
    failureCounter = 0;
  }
}

function sendData(argument, dataTag, data)
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function()
  {
    if (this.readyState == 4 && this.status == 200)
    {
      // We don't use the response string, don't worry about it.
      // var responseStr = this.responseText;
    }
  };
  var str = argument + "?";
  for (var i = 0; i < dataTag.length; i++)
  {
    str += dataTag[i] + "=" + data[i] + "&";
  }
  console.log(str);
  xhttp.open("GET", str, true); // true for asynchronous
  xhttp.send();
}

function getLI(target)
{
  while (target.nodeName.toLowerCase() != 'li' && target.nodeName.toLowerCase() != 'body')
  {
    target = target.parentNode;
  }
  if (target.nodeName.toLowerCase() == 'body')
  {
    return false;
  }
  else
  {
    return target;
  }
}

// Creates a new list item, either called from addBtn (below)
// or from the initial webpage loading when the ESP sends the
// cached list data.
function newElement(listItemNumber, listItemName, rTime, points)
{
  // First check to see if the listItemName was blank
  // (user accidentally clicked on Add before typing).
  if (listItemName === '')
  {
    return -1;
  }
  // Ensure we do not accidentally create a duplicate list
  // item with the same name as another list item.
  var list = document.getElementsByTagName("li");
  for (var i = 0; i < list.length; i++)
  {
    if (list[i].getAttribute("listItemName") == listItemName)
    {
      // This list item already exists.
      return -1;
    };
  }
  // We now know this is a new list item not already in the
  // list, so add it!
  var li = document.createElement("li");
  // Enable the draggable property.
  li.draggable = true;
  // Set attributes making it easier to isolate these parameters
  // in other functions.
  li.setAttribute("listItemName", listItemName);
  li.setAttribute("listItemNumber", listItemNumber);
  var t = document.createTextNode(listItemName);
  li.appendChild(t);
  document.getElementById("list").appendChild(li);
  // Reset the text input that the user typed.
  document.getElementById("myInput").value = "";

  // create the X
  var span = document.createElement("SPAN");
  var txt = document.createTextNode("\u00D7");
  span.className = "close";
  span.appendChild(txt);
  li.appendChild(span);

  // create the timer
  var timer = document.createElement("SPAN");
  var txt = document.createTextNode(rTime);
  timer.className = "timer";
  timer.appendChild(txt);
  li.appendChild(timer);
  
  // Create the reorder icon.
  var reOrder = document.createElement("SPAN");
  var txt = document.createTextNode("\u2630");
  reOrder.className = "reOrder";
  reOrder.appendChild(txt);
  li.appendChild(reOrder);

  var close = document.getElementsByClassName("close");
  for (i = 0; i < close.length; i++)
  {
    close[i].onclick = function()
    {
      var div = this.parentElement;
      var itemName = new Array(1);
      itemName[0] = div.getAttribute("listItemName");
      sendData("removeItem", [ "itemName" ], itemName);
      div.parentNode.removeChild(div);
    }
  }
  // Call this function to make the list item order proper
  // (i.e. 1-2-5-6-8-9 --> 1-2-3-4-5-6).
  reOrderListItemNumbers();
  // Indicate to addBtn() that we should proceed with sending
  // the parameters to the ESP.
  return 0;
}

// Create a new list item when clicking on the "Add" button
function addBtn()
{
  var inputValue = document.getElementById("myInput").value;
  // Get the time so we can send it to the ESP.
  const now = new Date();
  // Constant month names.
  const monthNames = [ "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                       "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" ];
  
  // Using a high number like 254 because this will be condensed
  // in the reOrderListItemNumbers() function later.
  if (newElement(254, inputValue, "Refresh page for due time", "999") == -1)
  {
    return;
  }
  const secondsSinceEpoch = Math.round(now.getTime() / 1000);

  // send GET request to server to add it to the physical list
  var dataTag = [ "itemName", "creationTime"    ];
  var data    = [ inputValue, secondsSinceEpoch ];
  
  sendData("addNewItem", dataTag, data);
}

function reOrderListItemNumbers()
{
  var list = document.getElementsByTagName("li");
  for (var i = 0; i < list.length; i++)
  {
    list[i].setAttribute("listItemNumber", i + 1);
  }
}

function checkCompleted()
{
  console.log("check completed!");
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function()
  {
    if (this.readyState == 4 && this.status == 200)
    {
      // Get the response from the ESP.
      var responseStr = this.responseText;
      // In the case of unfinished, do nothing. We only care
      // if the item was finished.
      var toParse = new URL(responseStr);
      var finishedArg = toParse.searchParams.get("finished");
      var streakCounterArg = toParse.searchParams.get("streakCounter");
      // Global variable gets updated here.
      newListItemDueTime = toParse.searchParams.get("dueTime");
      if (finishedArg == "true")
      {
        console.log("User pressed button!");
        var list = document.getElementsByTagName("li");
        var div = list[0];
        div.parentNode.removeChild(div);
        // Re-sync the list numbers (2,3,4,5... --> 1,2,3,4...).
        reOrderListItemNumbers();
        // Now we are back in sync.
      }
      // Update the streak counter with the data sent from the ESP.
      var streakTextElement = document.getElementById("streakText");
      if (streakTextElement)
      {
        streakTextElement.innerHTML = streakCounterArg;
      }
    }
  };
  // Get the time and send it to the ESP.
  const now = new Date();
  const secondsSinceEpoch = Math.round(now.getTime() / 1000);
  // Send the finishedItem request.
  var toSend = "finishedItem?time=" + secondsSinceEpoch.toString();
  xhttp.open("GET", toSend, true); // true for asynchronous
  xhttp.send();
}

    </script>
  </body>
</html>
)=====";

#endif
