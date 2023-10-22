// Copyright (c) 2023 Andrea Ballestrazzi

/**
 * Query the server info and update the page.
 */
function queryServerInfo() {
    fetch('/server-info')
        .then(response => response.json())
        .then(data => {
            document.querySelector("table tr:nth-child(2) td:nth-child(2)").innerHTML = data.server_version;
        });
}
