(async () => {
    for (var a of document.querySelectorAll("a[href]")) {
        var ok = false;
        for (var url of [a.href, "https://corsproxy.io/?" + encodeURIComponent(a.href)]) {
            try {
                const response = await fetch(url, { method: "HEAD", mode: "no-cors" });
                ok = true;
                break;
            } catch (err) {
                continue;
            }
        }
        if (!ok) {
            a.classList.add("broken");
            a.title = "Possibly a broken link.";
        }
    }
})();
