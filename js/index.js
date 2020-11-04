// 网站的所有页面列表
var pages = null;

// 网站url
var baseurl = location.href.split('?')[0];

// 假链接的跳转事件
function ajaxJump(url, isForward = false) {
    $('body,html').animate({ scrollTop: 0 }, 0);
    // 解析页面的url和其index
    var index = +url;
    if (isNaN(index)) {
        index = pages.indexOf(decodeURIComponent(url));
    } else {
        url = pages[index];
    }
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function() {
        if (xhr.status != 200) return;
        if (xhr.readyState != 4) return;
        var currentUrl = xhr.responseURL.replace(baseurl, '');
        var html = xhr.response;
        // markdown
        if (xhr.responseURL.indexOf('.md') != -1) {
            // marked.js会把\\(换行)改成\
            // marked.js会把\}(换行)改成}
            // marked.js会把\{(换行)改成{
            html = html
                .replace(/\\\\/g, '\\\\\\\\')
                .replace(/\\{/g, '\\\\{')
                .replace(/\\}/g, '\\\\}');
            html = marked(html);
        }
        // latex
        html = html.replace(/\$\$([\s\S]*?)\$\$/g, '<code class="language-math one-row-code">$1</code>');
        html = html.replace(/\$([\s\S]*?)\$/g, '<code class="language-math">$1</code>');
        // 相对路径
        var reg1 = new RegExp(/(src|href)="http/);
        var reg2 = new RegExp(/"(.*?)"/);
        var hrefs = html.match(/(href|src)="(.*?)"/g);
        var set = new Set();
        if (hrefs != null && hrefs.length) {
            for (var i = 0; i < hrefs.length; i++) {
                var href = hrefs[i];
                if (reg1.test(href)) continue;
                var _url = href.match(reg2)[1];
                if (set.has(_url)) continue;
                set.add(_url);
                html = html.replace(_url, relUrl2AbsUrl(_url, currentUrl));
            }
        }
        $('.center').html(html);
        // .center的ajax页面渲染完成后
        setTimeout(function() {
            // 代码处理
            $('pre code').each(function() {
                var $this = $(this);
                var code = $this.text();
                var language = $this.attr('class');
                if (!language) return;
                language = language.substring(9);

                // markdown 流程图
                if (language == 'mermaid') {
                    var id = 'diagram-' + new Date().getTime();
                    var $diagram = $('<div></div>');
                    $diagram.attr('id', id).insertAfter($this.parent());
                    var graph = mermaid.render(id + '-svg', code, function(svgCode, bindFunctions) {
                        $diagram.html(svgCode);
                    });
                    // var diagram = flowchart.parse(code);
                    // diagram.drawSVG(id);
                    $this.parent().remove();
                } else {
                    // 代码高亮
                    var codeHtml = hljs.highlightAuto(code, [language]).value;
                    $this.addClass('hljs ' + language).html(codeHtml);

                    // 添加行号
                    var codesplits = code.split('\n');
                    var ulHtml = [];
                    ulHtml.push('<ul class="code-row-no">');
                    for (var i = 0; i < codesplits.length; i++) {
                        ulHtml.push('<li>', i + 1, '</li>');
                    }
                    ulHtml.push('</ul>');
                    var $copy = $('<span class="code-copy">复制</span>');
                    $parent = $(this.parentNode);
                    $parent.prepend($copy, $(ulHtml.join('')));
                    // $parent.prepend($(ulHtml.join('')));
                    // 复制按钮
                    $copy.click(function() {
                        copy(code);
                        $copy.text('已复制');
                        setTimeout(function() {
                            $copy.text('复制');
                        }, 1000);
                    });
                }

            });
            // 禁用站内链接的默认跳转功能
            $('a').each(function() {
                var href = decodeURI($(this).attr('href')).replace(/\//g, '\\');
                if (href.lastIndexOf('.md') == href.length - 3) {
                    var index = pages.indexOf(href);
                    if (index == -1) return;
                    $(this).attr('href', 'javascript:void(0);')
                        .attr('data-url', index)
                        .addClass('ajax-link forward');
                } else {
                    $(this).attr('target', '_blank');
                }
            });
            // 图片居中
            $('.center img').each(function() {
                var $img = $(this);
                $img.click(function() {
                    // TODO: 点击查看大图
                    var $imagePanel = $('#image-panel');
                    if (!$imagePanel.length) {
                        $imagePanel = $('<div id="image-panel" class="panel"></div>');
                        $(document.body).append($imagePanel);
                    } else {
                        $imagePanel.find('img').remove();
                    }
                    var $bigImg = $('<img src="' + $img.attr('src') + '" />');
                    $imagePanel.append($bigImg);
                    $bigImg.load(function() {
                        $bigImg.css({
                            'margin-top': (($imagePanel.height() - $bigImg.height()) / 2) + 'px'
                        });
                    });

                    showPanel($imagePanel);
                });
                var $parent = $img.parent();
                if ($parent.attr('align') != 'center') {
                    var $prev = $img.prev();
                    var $newParent = $('<div align=center></div>');
                    $newParent.append($img);
                    if ($prev.length == 0) {
                        $newParent.appendTo($parent)
                    } else {
                        $newParent.insertAfter($prev);
                    }
                }
            });
            // latex渲染
            $('code.language-math').each(function() {
                try {
                    // marked.js解析会将$$\%$$解析成% 需要替换回来
                    var raw = $(this).text()
                        .replace(/\%/g, '\\%');
                    katex.render(raw, this);
                } catch (e) {
                    console.error(e);
                    console.error(raw);
                }
            });
        }, 200);
        // 判断是否是打开新页面还是替换页面
        if (isForward) {
            history.pushState(null, '', baseurl + '?' + index);
        } else {
            if (index == 0) {
                history.replaceState(null, '', baseurl);
            } else {
                history.replaceState(null, '', baseurl + '?' + index);
            }
        }
        // 选中与当前页面匹配左边笔记分类标签
        var $currentTag = $('.left .ajax-link[data-url=' + index + ']');
        if ($currentTag.length && !$currentTag.hasClass('selected')) {
            $('.left .ajax-link').removeClass('selected');
            $currentTag.addClass('selected');
        }
    }
    xhr.open('GET', url + '?_t=' + new Date());
    xhr.send();
}

// 用当前url计算出相对路径的绝对路径
function relUrl2AbsUrl(url, currentUrl) {
    var urlSplit = url.split('/');
    var cUrlSplit = currentUrl.split('/');
    cUrlSplit.length--;
    while (urlSplit.length > 0) {
        var cmd = urlSplit[0];
        if (cmd == '..' || cmd == '.' || cmd == '') {
            urlSplit.shift();
            if (cmd == '..') {
                cUrlSplit.length--;
            }
        } else {
            break;
        }
    }
    return cUrlSplit.join('/') + '/' + urlSplit.join('/');
}

// 绑定假链接的跳转事件
window.onclick = function(e) {
    var el = e.target;
    if (el.classList.contains('ajax-link')) {
        ajaxJump(el.getAttribute('data-url'), el.classList.contains('forward'));
        if (el.parentNode.classList.contains('left')) {
            $('.left .ajax-link').each(function() {
                this.classList.remove('selected');
            })
            el.classList.add('selected');
        }
    }
}

// 复制代码
function copy(str) {
    var save = function(e) {
        e.clipboardData.setData('text/plain', str); //下面会说到clipboardData对象
        e.preventDefault(); //阻止默认行为
    }
    document.addEventListener('copy', save);
    document.execCommand("copy"); //使文档处于可编辑状态，否则无效
}

// 浏览器地址栏变化(手动改变url,回退)事件 将ajax跳转
function pageLoad() {
    var index = location.search.replace('?', '');
    if (pages) {
        ajaxJump(index);
        return;
    }
    $.get('resources/pageMap.json?t=' + new Date().getTime()).then(res => {
        pages = res;
        ajaxJump(index);
    });
}

function closePanel() {
    document.getElementById('panel').style.display = 'none';
    $panelBackground.hide();
}

function showPanel($panel, panelTop = 0) {
    $panelBackground.show().css({
        top: window.scrollY + 'px'
    }).unbind('click').bind('click', function(e) {
        if (e.target.tagName != 'IMG') {
            $panel.hide();
            $panelBackground.hide();
            $(document.body).css({
                overflow: ''
            });
        }
    });
    $panelBackground.data('panel', $panel);
    $panel.show().css({
        top: (window.scrollY + panelTop) + 'px'
    });
    $(document.body).css({
        overflow: 'hidden'
    });
}

var $panelBackground;
$(function() {
    window.onpopstate = pageLoad;
    window.onload = pageLoad;
    $panelBackground = $('#panel-background');
    var $panel = $('#panel');
    var dataGeted = false;
    window.addEventListener('keyup', function(e) {
        if (e.altKey && e.key == '1') {
            if (!dataGeted) {
                $.get('statistic.json').then(function(data) {
                    $panel.html(JSON.stringify(data));
                    console.log(data);
                    dataGeted = true;
                });
            }
            showPanel($panel, 200);
        }
    });
});