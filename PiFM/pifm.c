




<!DOCTYPE html>
<html class="   ">
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# object: http://ogp.me/ns/object# article: http://ogp.me/ns/article# profile: http://ogp.me/ns/profile#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    
    
    <title>PirateRadio/pifm.c at master · Make-Magazine/PirateRadio</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />
    <link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-144.png" />
    <link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144.png" />
    <meta property="fb:app_id" content="1401488693436528"/>

      <meta content="@github" name="twitter:site" /><meta content="summary" name="twitter:card" /><meta content="Make-Magazine/PirateRadio" name="twitter:title" /><meta content="PirateRadio - Raspberry Pi Automated FM Radio Script" name="twitter:description" /><meta content="https://avatars0.githubusercontent.com/u/1308401?s=400" name="twitter:image:src" />
<meta content="GitHub" property="og:site_name" /><meta content="object" property="og:type" /><meta content="https://avatars0.githubusercontent.com/u/1308401?s=400" property="og:image" /><meta content="Make-Magazine/PirateRadio" property="og:title" /><meta content="https://github.com/Make-Magazine/PirateRadio" property="og:url" /><meta content="PirateRadio - Raspberry Pi Automated FM Radio Script" property="og:description" />

    <link rel="assets" href="https://github.global.ssl.fastly.net/">
    <link rel="conduit-xhr" href="https://ghconduit.com:25035/">
    <link rel="xhr-socket" href="/_sockets" />

    <meta name="msapplication-TileImage" content="/windows-tile.png" />
    <meta name="msapplication-TileColor" content="#ffffff" />
    <meta name="selected-link" value="repo_source" data-pjax-transient />
    <meta content="collector.githubapp.com" name="octolytics-host" /><meta content="collector-cdn.github.com" name="octolytics-script-host" /><meta content="github" name="octolytics-app-id" /><meta content="18087386:6B89:6A1D40C:536842EA" name="octolytics-dimension-request_id" /><meta content="56514" name="octolytics-actor-id" /><meta content="tomhiggins" name="octolytics-actor-login" /><meta content="39298c5b45166ae116d8c0be337d820bc8c507000f78f4c59d424239d8bae232" name="octolytics-actor-hash" />
    

    
    
    <link rel="icon" type="image/x-icon" href="https://github.global.ssl.fastly.net/favicon.ico" />

    <meta content="authenticity_token" name="csrf-param" />
<meta content="1oRb5BvVD2Pt+BbKXuAXkToEK6d7J3VqTj6yLJ4C5o8hcZY4jwHTqt6QpYaBnC4K2HPKayLcCQb1hgSdkymfHA==" name="csrf-token" />

    <link href="https://github.global.ssl.fastly.net/assets/github-dd66c24faee93eaa771501154e779c24d1885a60.css" media="all" rel="stylesheet" type="text/css" />
    <link href="https://github.global.ssl.fastly.net/assets/github2-96650e7fd26c88d259f1425ece09ffa2223cdcea.css" media="all" rel="stylesheet" type="text/css" />
    


        <script crossorigin="anonymous" src="https://github.global.ssl.fastly.net/assets/frameworks-2f6219cf5b1c2bab818848f5705fab73e1f57022.js" type="text/javascript"></script>
        <script async="async" crossorigin="anonymous" src="https://github.global.ssl.fastly.net/assets/github-ceedfd14494501a450c1f2934fa5c21858769efb.js" type="text/javascript"></script>
        
        
      <meta http-equiv="x-pjax-version" content="eba0f8a899d3e16611fcb1be09d60000">

      
  <meta name="description" content="PirateRadio - Raspberry Pi Automated FM Radio Script" />

  <meta content="1308401" name="octolytics-dimension-user_id" /><meta content="Make-Magazine" name="octolytics-dimension-user_login" /><meta content="17536738" name="octolytics-dimension-repository_id" /><meta content="Make-Magazine/PirateRadio" name="octolytics-dimension-repository_nwo" /><meta content="true" name="octolytics-dimension-repository_public" /><meta content="false" name="octolytics-dimension-repository_is_fork" /><meta content="17536738" name="octolytics-dimension-repository_network_root_id" /><meta content="Make-Magazine/PirateRadio" name="octolytics-dimension-repository_network_root_nwo" />
  <link href="https://github.com/Make-Magazine/PirateRadio/commits/master.atom" rel="alternate" title="Recent Commits to PirateRadio:master" type="application/atom+xml" />

  </head>


  <body class="logged_in  env-production linux vis-public page-blob">
    <a href="#start-of-content" tabindex="1" class="accessibility-aid js-skip-to-content">Skip to content</a>
    <div class="wrapper">
      
      
      
      


      <div class="header header-logged-in true">
  <div class="container clearfix">

    <a class="header-logo-invertocat" href="https://github.com/">
  <span class="mega-octicon octicon-mark-github"></span>
</a>

    
    <a href="/notifications" aria-label="You have unread notifications" class="notification-indicator tooltipped tooltipped-s" data-hotkey="g n">
        <span class="mail-status unread"></span>
</a>

      <div class="command-bar js-command-bar  in-repository">
          <form accept-charset="UTF-8" action="/search" class="command-bar-form" id="top_search_form" method="get">

<div class="commandbar">
  <span class="message"></span>
  <input type="text" data-hotkey="s, /" name="q" id="js-command-bar-field" placeholder="Search or type a command" tabindex="1" autocapitalize="off"
    
    data-username="tomhiggins"
      data-repo="Make-Magazine/PirateRadio"
      data-branch="master"
      data-sha="04a1c00b25b28774beccb3f1100448238688c27f"
  >
  <div class="display hidden"></div>
</div>

    <input type="hidden" name="nwo" value="Make-Magazine/PirateRadio" />

    <div class="select-menu js-menu-container js-select-menu search-context-select-menu">
      <span class="minibutton select-menu-button js-menu-target" role="button" aria-haspopup="true">
        <span class="js-select-button">This repository</span>
      </span>

      <div class="select-menu-modal-holder js-menu-content js-navigation-container" aria-hidden="true">
        <div class="select-menu-modal">

          <div class="select-menu-item js-navigation-item js-this-repository-navigation-item selected">
            <span class="select-menu-item-icon octicon octicon-check"></span>
            <input type="radio" class="js-search-this-repository" name="search_target" value="repository" checked="checked" />
            <div class="select-menu-item-text js-select-button-text">This repository</div>
          </div> <!-- /.select-menu-item -->

          <div class="select-menu-item js-navigation-item js-all-repositories-navigation-item">
            <span class="select-menu-item-icon octicon octicon-check"></span>
            <input type="radio" name="search_target" value="global" />
            <div class="select-menu-item-text js-select-button-text">All repositories</div>
          </div> <!-- /.select-menu-item -->

        </div>
      </div>
    </div>

  <span class="help tooltipped tooltipped-s" aria-label="Show command bar help">
    <span class="octicon octicon-question"></span>
  </span>


  <input type="hidden" name="ref" value="cmdform">

</form>
        <ul class="top-nav">
          <li class="explore"><a href="/explore">Explore</a></li>
            <li><a href="https://gist.github.com">Gist</a></li>
            <li><a href="/blog">Blog</a></li>
          <li><a href="https://help.github.com">Help</a></li>
        </ul>
      </div>

    


  <ul id="user-links">
    <li>
      <a href="/tomhiggins" class="name">
        <img alt="Tom Higgins" class=" js-avatar" data-user="56514" height="20" src="https://avatars2.githubusercontent.com/u/56514?s=140" width="20" /> tomhiggins
      </a>
    </li>

    <li class="new-menu dropdown-toggle js-menu-container">
      <a href="#" class="js-menu-target tooltipped tooltipped-s" aria-label="Create new...">
        <span class="octicon octicon-plus"></span>
        <span class="dropdown-arrow"></span>
      </a>

      <div class="new-menu-content js-menu-content">
      </div>
    </li>

    <li>
      <a href="/settings/profile" id="account_settings"
        class="tooltipped tooltipped-s"
        aria-label="Account settings ">
        <span class="octicon octicon-tools"></span>
      </a>
    </li>
    <li>
      <form class="logout-form" action="/logout" method="post">
        <button class="sign-out-button tooltipped tooltipped-s" aria-label="Sign out">
          <span class="octicon octicon-log-out"></span>
        </button>
      </form>
    </li>

  </ul>

<div class="js-new-dropdown-contents hidden">
  

<ul class="dropdown-menu">
  <li>
    <a href="/new"><span class="octicon octicon-repo-create"></span> New repository</a>
  </li>
  <li>
    <a href="/organizations/new"><span class="octicon octicon-organization"></span> New organization</a>
  </li>


    <li class="section-title">
      <span title="Make-Magazine/PirateRadio">This repository</span>
    </li>
      <li>
        <a href="/Make-Magazine/PirateRadio/issues/new"><span class="octicon octicon-issue-opened"></span> New issue</a>
      </li>
</ul>

</div>


    
  </div>
</div>

      

        



      <div id="start-of-content" class="accessibility-aid"></div>
          <div class="site" itemscope itemtype="http://schema.org/WebPage">
    <div id="js-flash-container">
      
    </div>
    <div class="pagehead repohead instapaper_ignore readability-menu">
      <div class="container">
        

<ul class="pagehead-actions">

    <li class="subscription">
      <form accept-charset="UTF-8" action="/notifications/subscribe" class="js-social-container" data-autosubmit="true" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="brw0B5KU0XJktUFkcJaaT+DmzNA1EGnIy5nl1Za5QBDDm6J8AzxTygqicCs+O5jyTwQn7QAXKyEAUFD9k/dvCg==" /></div>  <input id="repository_id" name="repository_id" type="hidden" value="17536738" />

    <div class="select-menu js-menu-container js-select-menu">
      <a class="social-count js-social-count" href="/Make-Magazine/PirateRadio/watchers">
        24
      </a>
      <span class="minibutton select-menu-button with-count js-menu-target" role="button" tabindex="0" aria-haspopup="true">
        <span class="js-select-button">
          <span class="octicon octicon-eye-watch"></span>
          Watch
        </span>
      </span>

      <div class="select-menu-modal-holder">
        <div class="select-menu-modal subscription-menu-modal js-menu-content" aria-hidden="true">
          <div class="select-menu-header">
            <span class="select-menu-title">Notification status</span>
            <span class="octicon octicon-remove-close js-menu-close"></span>
          </div> <!-- /.select-menu-header -->

          <div class="select-menu-list js-navigation-container" role="menu">

            <div class="select-menu-item js-navigation-item selected" role="menuitem" tabindex="0">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <div class="select-menu-item-text">
                <input checked="checked" id="do_included" name="do" type="radio" value="included" />
                <h4>Not watching</h4>
                <span class="description">You only receive notifications for conversations in which you participate or are @mentioned.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="octicon octicon-eye-watch"></span>
                  Watch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
              <span class="select-menu-item-icon octicon octicon octicon-check"></span>
              <div class="select-menu-item-text">
                <input id="do_subscribed" name="do" type="radio" value="subscribed" />
                <h4>Watching</h4>
                <span class="description">You receive notifications for all conversations in this repository.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="octicon octicon-eye-unwatch"></span>
                  Unwatch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <div class="select-menu-item-text">
                <input id="do_ignore" name="do" type="radio" value="ignore" />
                <h4>Ignoring</h4>
                <span class="description">You do not receive any notifications for conversations in this repository.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="octicon octicon-mute"></span>
                  Stop ignoring
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

          </div> <!-- /.select-menu-list -->

        </div> <!-- /.select-menu-modal -->
      </div> <!-- /.select-menu-modal-holder -->
    </div> <!-- /.select-menu -->

</form>
    </li>

  <li>
  

  <div class="js-toggler-container js-social-container starring-container ">

    <form accept-charset="UTF-8" action="/Make-Magazine/PirateRadio/unstar" class="js-toggler-form starred" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="zGTAHKEFMtk8Kaf93EztemD9ZO7/GIaivmKwtWuetS27y5+fTieAqlkBHDwp4EIc0x1/OHJR7gkawL1KqwQOJw==" /></div>
      <button
        class="minibutton with-count js-toggler-target star-button"
        aria-label="Unstar this repository" title="Unstar Make-Magazine/PirateRadio">
        <span class="octicon octicon-star-delete"></span><span class="text">Unstar</span>
      </button>
        <a class="social-count js-social-count" href="/Make-Magazine/PirateRadio/stargazers">
          73
        </a>
</form>
    <form accept-charset="UTF-8" action="/Make-Magazine/PirateRadio/star" class="js-toggler-form unstarred" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="1Prk3yyQPNVpAxDbbGQOl0lq4lblmuulQh/5hB1BukY0lDGkV2lJbeZGhiiiMOQ46l0AiRz8+7VUGjHpAWRqEw==" /></div>
      <button
        class="minibutton with-count js-toggler-target star-button"
        aria-label="Star this repository" title="Star Make-Magazine/PirateRadio">
        <span class="octicon octicon-star"></span><span class="text">Star</span>
      </button>
        <a class="social-count js-social-count" href="/Make-Magazine/PirateRadio/stargazers">
          73
        </a>
</form>  </div>

  </li>


        <li>
          <a href="/Make-Magazine/PirateRadio/fork" class="minibutton with-count js-toggler-target fork-button lighter tooltipped-n" title="Fork your own copy of Make-Magazine/PirateRadio to your account" aria-label="Fork your own copy of Make-Magazine/PirateRadio to your account" rel="nofollow" data-method="post">
            <span class="octicon octicon-git-branch-create"></span><span class="text">Fork</span>
          </a>
          <a href="/Make-Magazine/PirateRadio/network" class="social-count">23</a>
        </li>


</ul>

        <h1 itemscope itemtype="http://data-vocabulary.org/Breadcrumb" class="entry-title public">
          <span class="repo-label"><span>public</span></span>
          <span class="mega-octicon octicon-repo"></span>
          <span class="author"><a href="/Make-Magazine" class="url fn" itemprop="url" rel="author"><span itemprop="title">Make-Magazine</span></a></span><!--
       --><span class="path-divider">/</span><!--
       --><strong><a href="/Make-Magazine/PirateRadio" class="js-current-repository js-repo-home-link">PirateRadio</a></strong>

          <span class="page-context-loader">
            <img alt="Octocat-spinner-32" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
          </span>

        </h1>
      </div><!-- /.container -->
    </div><!-- /.repohead -->

    <div class="container">
      <div class="repository-with-sidebar repo-container new-discussion-timeline js-new-discussion-timeline  ">
        <div class="repository-sidebar clearfix">
            

<div class="sunken-menu vertical-right repo-nav js-repo-nav js-repository-container-pjax js-octicon-loaders">
  <div class="sunken-menu-contents">
    <ul class="sunken-menu-group">
      <li class="tooltipped tooltipped-w" aria-label="Code">
        <a href="/Make-Magazine/PirateRadio" aria-label="Code" class="selected js-selected-navigation-item sunken-menu-item" data-hotkey="g c" data-pjax="true" data-selected-links="repo_source repo_downloads repo_commits repo_releases repo_tags repo_branches /Make-Magazine/PirateRadio">
          <span class="octicon octicon-code"></span> <span class="full-word">Code</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

        <li class="tooltipped tooltipped-w" aria-label="Issues">
          <a href="/Make-Magazine/PirateRadio/issues" aria-label="Issues" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-hotkey="g i" data-selected-links="repo_issues /Make-Magazine/PirateRadio/issues">
            <span class="octicon octicon-issue-opened"></span> <span class="full-word">Issues</span>
            <span class='counter'>5</span>
            <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>        </li>

      <li class="tooltipped tooltipped-w" aria-label="Pull Requests">
        <a href="/Make-Magazine/PirateRadio/pulls" aria-label="Pull Requests" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-hotkey="g p" data-selected-links="repo_pulls /Make-Magazine/PirateRadio/pulls">
            <span class="octicon octicon-git-pull-request"></span> <span class="full-word">Pull Requests</span>
            <span class='counter'>1</span>
            <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>


        <li class="tooltipped tooltipped-w" aria-label="Wiki">
          <a href="/Make-Magazine/PirateRadio/wiki" aria-label="Wiki" class="js-selected-navigation-item sunken-menu-item" data-hotkey="g w" data-pjax="true" data-selected-links="repo_wiki /Make-Magazine/PirateRadio/wiki">
            <span class="octicon octicon-book"></span> <span class="full-word">Wiki</span>
            <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>        </li>
    </ul>
    <div class="sunken-menu-separator"></div>
    <ul class="sunken-menu-group">

      <li class="tooltipped tooltipped-w" aria-label="Pulse">
        <a href="/Make-Magazine/PirateRadio/pulse" aria-label="Pulse" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="pulse /Make-Magazine/PirateRadio/pulse">
          <span class="octicon octicon-pulse"></span> <span class="full-word">Pulse</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

      <li class="tooltipped tooltipped-w" aria-label="Graphs">
        <a href="/Make-Magazine/PirateRadio/graphs" aria-label="Graphs" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="repo_graphs repo_contributors /Make-Magazine/PirateRadio/graphs">
          <span class="octicon octicon-graph"></span> <span class="full-word">Graphs</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

      <li class="tooltipped tooltipped-w" aria-label="Network">
        <a href="/Make-Magazine/PirateRadio/network" aria-label="Network" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-selected-links="repo_network /Make-Magazine/PirateRadio/network">
          <span class="octicon octicon-git-branch"></span> <span class="full-word">Network</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>
    </ul>


  </div>
</div>

              <div class="only-with-full-nav">
                

  

<div class="clone-url open"
  data-protocol-type="http"
  data-url="/users/set_protocol?protocol_selector=http&amp;protocol_type=clone">
  <h3><strong>HTTPS</strong> clone URL</h3>
  <div class="clone-url-box">
    <input type="text" class="clone js-url-field"
           value="https://github.com/Make-Magazine/PirateRadio.git" readonly="readonly">
    <span class="url-box-clippy">
    <button aria-label="copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="https://github.com/Make-Magazine/PirateRadio.git" data-copied-hint="copied!" type="button"><span class="octicon octicon-clippy"></span></button>
    </span>
  </div>
</div>

  

<div class="clone-url "
  data-protocol-type="ssh"
  data-url="/users/set_protocol?protocol_selector=ssh&amp;protocol_type=clone">
  <h3><strong>SSH</strong> clone URL</h3>
  <div class="clone-url-box">
    <input type="text" class="clone js-url-field"
           value="git@github.com:Make-Magazine/PirateRadio.git" readonly="readonly">
    <span class="url-box-clippy">
    <button aria-label="copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="git@github.com:Make-Magazine/PirateRadio.git" data-copied-hint="copied!" type="button"><span class="octicon octicon-clippy"></span></button>
    </span>
  </div>
</div>

  

<div class="clone-url "
  data-protocol-type="subversion"
  data-url="/users/set_protocol?protocol_selector=subversion&amp;protocol_type=clone">
  <h3><strong>Subversion</strong> checkout URL</h3>
  <div class="clone-url-box">
    <input type="text" class="clone js-url-field"
           value="https://github.com/Make-Magazine/PirateRadio" readonly="readonly">
    <span class="url-box-clippy">
    <button aria-label="copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="https://github.com/Make-Magazine/PirateRadio" data-copied-hint="copied!" type="button"><span class="octicon octicon-clippy"></span></button>
    </span>
  </div>
</div>


<p class="clone-options">You can clone with
      <a href="#" class="js-clone-selector" data-protocol="http">HTTPS</a>,
      <a href="#" class="js-clone-selector" data-protocol="ssh">SSH</a>,
      or <a href="#" class="js-clone-selector" data-protocol="subversion">Subversion</a>.
  <span class="help tooltipped tooltipped-n" aria-label="Get help on which URL is right for you.">
    <a href="https://help.github.com/articles/which-remote-url-should-i-use">
    <span class="octicon octicon-question"></span>
    </a>
  </span>
</p>



                <a href="/Make-Magazine/PirateRadio/archive/master.zip"
                   class="minibutton sidebar-button"
                   aria-label="Download Make-Magazine/PirateRadio as a zip file"
                   title="Download Make-Magazine/PirateRadio as a zip file"
                   rel="nofollow">
                  <span class="octicon octicon-cloud-download"></span>
                  Download ZIP
                </a>
              </div>
        </div><!-- /.repository-sidebar -->

        <div id="js-repo-pjax-container" class="repository-content context-loader-container" data-pjax-container>
          

<a href="/Make-Magazine/PirateRadio/blob/093df74e8d1af67fe406460a0b9886cb044096f6/pifm.c" class="hidden js-permalink-shortcut" data-hotkey="y">Permalink</a>

<!-- blob contrib key: blob_contributors:v21:046c34d0a6b8c8e9969a71d7b3d37da2 -->

<p title="This is a placeholder element" class="js-history-link-replace hidden"></p>

<a href="/Make-Magazine/PirateRadio/find/master" data-pjax data-hotkey="t" class="js-show-file-finder" style="display:none">Show File Finder</a>

<div class="file-navigation">
  

<div class="select-menu js-menu-container js-select-menu" >
  <span class="minibutton select-menu-button js-menu-target" data-hotkey="w"
    data-master-branch="master"
    data-ref="master"
    role="button" aria-label="Switch branches or tags" tabindex="0" aria-haspopup="true">
    <span class="octicon octicon-git-branch"></span>
    <i>branch:</i>
    <span class="js-select-button">master</span>
  </span>

  <div class="select-menu-modal-holder js-menu-content js-navigation-container" data-pjax aria-hidden="true">

    <div class="select-menu-modal">
      <div class="select-menu-header">
        <span class="select-menu-title">Switch branches/tags</span>
        <span class="octicon octicon-remove-close js-menu-close"></span>
      </div> <!-- /.select-menu-header -->

      <div class="select-menu-filters">
        <div class="select-menu-text-filter">
          <input type="text" aria-label="Filter branches/tags" id="context-commitish-filter-field" class="js-filterable-field js-navigation-enable" placeholder="Filter branches/tags">
        </div>
        <div class="select-menu-tabs">
          <ul>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="branches" class="js-select-menu-tab">Branches</a>
            </li>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="tags" class="js-select-menu-tab">Tags</a>
            </li>
          </ul>
        </div><!-- /.select-menu-tabs -->
      </div><!-- /.select-menu-filters -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="branches">

        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


            <div class="select-menu-item js-navigation-item selected">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Make-Magazine/PirateRadio/blob/master/pifm.c"
                 data-name="master"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="master">master</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Make-Magazine/PirateRadio/blob/unstable/pifm.c"
                 data-name="unstable"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="unstable">unstable</a>
            </div> <!-- /.select-menu-item -->
        </div>

          <div class="select-menu-no-results">Nothing to show</div>
      </div> <!-- /.select-menu-list -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="tags">
        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


        </div>

        <div class="select-menu-no-results">Nothing to show</div>
      </div> <!-- /.select-menu-list -->

    </div> <!-- /.select-menu-modal -->
  </div> <!-- /.select-menu-modal-holder -->
</div> <!-- /.select-menu -->

  <div class="breadcrumb">
    <span class='repo-root js-repo-root'><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/Make-Magazine/PirateRadio" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">PirateRadio</span></a></span></span><span class="separator"> / </span><strong class="final-path">pifm.c</strong> <button aria-label="copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="pifm.c" data-copied-hint="copied!" type="button"><span class="octicon octicon-clippy"></span></button>
  </div>
</div>


  <div class="commit file-history-tease">
    <img alt="Sahaj Sarup" class="main-avatar js-avatar" data-user="5900740" height="24" src="https://avatars3.githubusercontent.com/u/5900740?s=140" width="24" />
    <span class="author"><a href="/ric96" rel="author">ric96</a></span>
    <local-time datetime="2014-04-08T23:54:45+05:30" from="now" title-format="%Y-%m-%d %H:%M:%S %z" title="2014-04-08 23:54:45 +0530">April 08, 2014</local-time>
    <div class="commit-title">
        <a href="/Make-Magazine/PirateRadio/commit/484e18910607471cbf94d66a3bd728cbba00ad01" class="message" data-pjax="true" title="improved quality

That will cause the pilot tone deviation to increase from 3.9 kHz to 7 kHz (make it stronger.)
It will also cause the modulation to decrease, i.e. make the sound quieter. Which is a good thing, because as delivered it over-modulates, it disturbs neighboring channels">improved quality</a>
    </div>

    <div class="participation">
      <p class="quickstat"><a href="#blob_contributors_box" rel="facebox"><strong>2</strong>  contributors</a></p>
          <a class="avatar tooltipped tooltipped-s" aria-label="ric96" href="/Make-Magazine/PirateRadio/commits/master/pifm.c?author=ric96"><img alt="Sahaj Sarup" class=" js-avatar" data-user="5900740" height="20" src="https://avatars3.githubusercontent.com/u/5900740?s=140" width="20" /></a>
    <a class="avatar tooltipped tooltipped-s" aria-label="d4m4s74" href="/Make-Magazine/PirateRadio/commits/master/pifm.c?author=d4m4s74"><img alt="d4m4s74" class=" js-avatar" data-user="3111946" height="20" src="https://avatars2.githubusercontent.com/u/3111946?s=140" width="20" /></a>


    </div>
    <div id="blob_contributors_box" style="display:none">
      <h2 class="facebox-header">Users who have contributed to this file</h2>
      <ul class="facebox-user-list">
          <li class="facebox-user-list-item">
            <img alt="Sahaj Sarup" class=" js-avatar" data-user="5900740" height="24" src="https://avatars3.githubusercontent.com/u/5900740?s=140" width="24" />
            <a href="/ric96">ric96</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="d4m4s74" class=" js-avatar" data-user="3111946" height="24" src="https://avatars2.githubusercontent.com/u/3111946?s=140" width="24" />
            <a href="/d4m4s74">d4m4s74</a>
          </li>
      </ul>
    </div>
  </div>

<div class="file-box">
  <div class="file">
    <div class="meta clearfix">
      <div class="info file-name">
        <span class="icon"><b class="octicon octicon-file-text"></b></span>
        <span class="mode" title="File Mode">file</span>
        <span class="meta-divider"></span>
          <span>660 lines (518 sloc)</span>
          <span class="meta-divider"></span>
        <span>21.258 kb</span>
      </div>
      <div class="actions">
        <div class="button-group">
                <a class="minibutton tooltipped tooltipped-n js-update-url-with-hash"
                   aria-label="Clicking this button will automatically fork this project so you can edit the file"
                   href="/Make-Magazine/PirateRadio/edit/master/pifm.c"
                   data-method="post" rel="nofollow">Edit</a>
          <a href="/Make-Magazine/PirateRadio/raw/master/pifm.c" class="button minibutton " id="raw-url">Raw</a>
            <a href="/Make-Magazine/PirateRadio/blame/master/pifm.c" class="button minibutton js-update-url-with-hash">Blame</a>
          <a href="/Make-Magazine/PirateRadio/commits/master/pifm.c" class="button minibutton " rel="nofollow">History</a>
        </div><!-- /.button-group -->

            <a class="minibutton danger empty-icon tooltipped tooltipped-s"
               href="/Make-Magazine/PirateRadio/delete/master/pifm.c"
               aria-label="Fork this project and delete file"
               data-method="post" data-test-id="delete-blob-file" rel="nofollow">

          Delete
        </a>
      </div><!-- /.actions -->
    </div>
        <div class="blob-wrapper data type-c js-blob-data">
        <table class="file-code file-diff tab-size-8">
          <tr class="file-code-line">
            <td class="blob-line-nums">
              <span id="L1" rel="#L1">1</span>
<span id="L2" rel="#L2">2</span>
<span id="L3" rel="#L3">3</span>
<span id="L4" rel="#L4">4</span>
<span id="L5" rel="#L5">5</span>
<span id="L6" rel="#L6">6</span>
<span id="L7" rel="#L7">7</span>
<span id="L8" rel="#L8">8</span>
<span id="L9" rel="#L9">9</span>
<span id="L10" rel="#L10">10</span>
<span id="L11" rel="#L11">11</span>
<span id="L12" rel="#L12">12</span>
<span id="L13" rel="#L13">13</span>
<span id="L14" rel="#L14">14</span>
<span id="L15" rel="#L15">15</span>
<span id="L16" rel="#L16">16</span>
<span id="L17" rel="#L17">17</span>
<span id="L18" rel="#L18">18</span>
<span id="L19" rel="#L19">19</span>
<span id="L20" rel="#L20">20</span>
<span id="L21" rel="#L21">21</span>
<span id="L22" rel="#L22">22</span>
<span id="L23" rel="#L23">23</span>
<span id="L24" rel="#L24">24</span>
<span id="L25" rel="#L25">25</span>
<span id="L26" rel="#L26">26</span>
<span id="L27" rel="#L27">27</span>
<span id="L28" rel="#L28">28</span>
<span id="L29" rel="#L29">29</span>
<span id="L30" rel="#L30">30</span>
<span id="L31" rel="#L31">31</span>
<span id="L32" rel="#L32">32</span>
<span id="L33" rel="#L33">33</span>
<span id="L34" rel="#L34">34</span>
<span id="L35" rel="#L35">35</span>
<span id="L36" rel="#L36">36</span>
<span id="L37" rel="#L37">37</span>
<span id="L38" rel="#L38">38</span>
<span id="L39" rel="#L39">39</span>
<span id="L40" rel="#L40">40</span>
<span id="L41" rel="#L41">41</span>
<span id="L42" rel="#L42">42</span>
<span id="L43" rel="#L43">43</span>
<span id="L44" rel="#L44">44</span>
<span id="L45" rel="#L45">45</span>
<span id="L46" rel="#L46">46</span>
<span id="L47" rel="#L47">47</span>
<span id="L48" rel="#L48">48</span>
<span id="L49" rel="#L49">49</span>
<span id="L50" rel="#L50">50</span>
<span id="L51" rel="#L51">51</span>
<span id="L52" rel="#L52">52</span>
<span id="L53" rel="#L53">53</span>
<span id="L54" rel="#L54">54</span>
<span id="L55" rel="#L55">55</span>
<span id="L56" rel="#L56">56</span>
<span id="L57" rel="#L57">57</span>
<span id="L58" rel="#L58">58</span>
<span id="L59" rel="#L59">59</span>
<span id="L60" rel="#L60">60</span>
<span id="L61" rel="#L61">61</span>
<span id="L62" rel="#L62">62</span>
<span id="L63" rel="#L63">63</span>
<span id="L64" rel="#L64">64</span>
<span id="L65" rel="#L65">65</span>
<span id="L66" rel="#L66">66</span>
<span id="L67" rel="#L67">67</span>
<span id="L68" rel="#L68">68</span>
<span id="L69" rel="#L69">69</span>
<span id="L70" rel="#L70">70</span>
<span id="L71" rel="#L71">71</span>
<span id="L72" rel="#L72">72</span>
<span id="L73" rel="#L73">73</span>
<span id="L74" rel="#L74">74</span>
<span id="L75" rel="#L75">75</span>
<span id="L76" rel="#L76">76</span>
<span id="L77" rel="#L77">77</span>
<span id="L78" rel="#L78">78</span>
<span id="L79" rel="#L79">79</span>
<span id="L80" rel="#L80">80</span>
<span id="L81" rel="#L81">81</span>
<span id="L82" rel="#L82">82</span>
<span id="L83" rel="#L83">83</span>
<span id="L84" rel="#L84">84</span>
<span id="L85" rel="#L85">85</span>
<span id="L86" rel="#L86">86</span>
<span id="L87" rel="#L87">87</span>
<span id="L88" rel="#L88">88</span>
<span id="L89" rel="#L89">89</span>
<span id="L90" rel="#L90">90</span>
<span id="L91" rel="#L91">91</span>
<span id="L92" rel="#L92">92</span>
<span id="L93" rel="#L93">93</span>
<span id="L94" rel="#L94">94</span>
<span id="L95" rel="#L95">95</span>
<span id="L96" rel="#L96">96</span>
<span id="L97" rel="#L97">97</span>
<span id="L98" rel="#L98">98</span>
<span id="L99" rel="#L99">99</span>
<span id="L100" rel="#L100">100</span>
<span id="L101" rel="#L101">101</span>
<span id="L102" rel="#L102">102</span>
<span id="L103" rel="#L103">103</span>
<span id="L104" rel="#L104">104</span>
<span id="L105" rel="#L105">105</span>
<span id="L106" rel="#L106">106</span>
<span id="L107" rel="#L107">107</span>
<span id="L108" rel="#L108">108</span>
<span id="L109" rel="#L109">109</span>
<span id="L110" rel="#L110">110</span>
<span id="L111" rel="#L111">111</span>
<span id="L112" rel="#L112">112</span>
<span id="L113" rel="#L113">113</span>
<span id="L114" rel="#L114">114</span>
<span id="L115" rel="#L115">115</span>
<span id="L116" rel="#L116">116</span>
<span id="L117" rel="#L117">117</span>
<span id="L118" rel="#L118">118</span>
<span id="L119" rel="#L119">119</span>
<span id="L120" rel="#L120">120</span>
<span id="L121" rel="#L121">121</span>
<span id="L122" rel="#L122">122</span>
<span id="L123" rel="#L123">123</span>
<span id="L124" rel="#L124">124</span>
<span id="L125" rel="#L125">125</span>
<span id="L126" rel="#L126">126</span>
<span id="L127" rel="#L127">127</span>
<span id="L128" rel="#L128">128</span>
<span id="L129" rel="#L129">129</span>
<span id="L130" rel="#L130">130</span>
<span id="L131" rel="#L131">131</span>
<span id="L132" rel="#L132">132</span>
<span id="L133" rel="#L133">133</span>
<span id="L134" rel="#L134">134</span>
<span id="L135" rel="#L135">135</span>
<span id="L136" rel="#L136">136</span>
<span id="L137" rel="#L137">137</span>
<span id="L138" rel="#L138">138</span>
<span id="L139" rel="#L139">139</span>
<span id="L140" rel="#L140">140</span>
<span id="L141" rel="#L141">141</span>
<span id="L142" rel="#L142">142</span>
<span id="L143" rel="#L143">143</span>
<span id="L144" rel="#L144">144</span>
<span id="L145" rel="#L145">145</span>
<span id="L146" rel="#L146">146</span>
<span id="L147" rel="#L147">147</span>
<span id="L148" rel="#L148">148</span>
<span id="L149" rel="#L149">149</span>
<span id="L150" rel="#L150">150</span>
<span id="L151" rel="#L151">151</span>
<span id="L152" rel="#L152">152</span>
<span id="L153" rel="#L153">153</span>
<span id="L154" rel="#L154">154</span>
<span id="L155" rel="#L155">155</span>
<span id="L156" rel="#L156">156</span>
<span id="L157" rel="#L157">157</span>
<span id="L158" rel="#L158">158</span>
<span id="L159" rel="#L159">159</span>
<span id="L160" rel="#L160">160</span>
<span id="L161" rel="#L161">161</span>
<span id="L162" rel="#L162">162</span>
<span id="L163" rel="#L163">163</span>
<span id="L164" rel="#L164">164</span>
<span id="L165" rel="#L165">165</span>
<span id="L166" rel="#L166">166</span>
<span id="L167" rel="#L167">167</span>
<span id="L168" rel="#L168">168</span>
<span id="L169" rel="#L169">169</span>
<span id="L170" rel="#L170">170</span>
<span id="L171" rel="#L171">171</span>
<span id="L172" rel="#L172">172</span>
<span id="L173" rel="#L173">173</span>
<span id="L174" rel="#L174">174</span>
<span id="L175" rel="#L175">175</span>
<span id="L176" rel="#L176">176</span>
<span id="L177" rel="#L177">177</span>
<span id="L178" rel="#L178">178</span>
<span id="L179" rel="#L179">179</span>
<span id="L180" rel="#L180">180</span>
<span id="L181" rel="#L181">181</span>
<span id="L182" rel="#L182">182</span>
<span id="L183" rel="#L183">183</span>
<span id="L184" rel="#L184">184</span>
<span id="L185" rel="#L185">185</span>
<span id="L186" rel="#L186">186</span>
<span id="L187" rel="#L187">187</span>
<span id="L188" rel="#L188">188</span>
<span id="L189" rel="#L189">189</span>
<span id="L190" rel="#L190">190</span>
<span id="L191" rel="#L191">191</span>
<span id="L192" rel="#L192">192</span>
<span id="L193" rel="#L193">193</span>
<span id="L194" rel="#L194">194</span>
<span id="L195" rel="#L195">195</span>
<span id="L196" rel="#L196">196</span>
<span id="L197" rel="#L197">197</span>
<span id="L198" rel="#L198">198</span>
<span id="L199" rel="#L199">199</span>
<span id="L200" rel="#L200">200</span>
<span id="L201" rel="#L201">201</span>
<span id="L202" rel="#L202">202</span>
<span id="L203" rel="#L203">203</span>
<span id="L204" rel="#L204">204</span>
<span id="L205" rel="#L205">205</span>
<span id="L206" rel="#L206">206</span>
<span id="L207" rel="#L207">207</span>
<span id="L208" rel="#L208">208</span>
<span id="L209" rel="#L209">209</span>
<span id="L210" rel="#L210">210</span>
<span id="L211" rel="#L211">211</span>
<span id="L212" rel="#L212">212</span>
<span id="L213" rel="#L213">213</span>
<span id="L214" rel="#L214">214</span>
<span id="L215" rel="#L215">215</span>
<span id="L216" rel="#L216">216</span>
<span id="L217" rel="#L217">217</span>
<span id="L218" rel="#L218">218</span>
<span id="L219" rel="#L219">219</span>
<span id="L220" rel="#L220">220</span>
<span id="L221" rel="#L221">221</span>
<span id="L222" rel="#L222">222</span>
<span id="L223" rel="#L223">223</span>
<span id="L224" rel="#L224">224</span>
<span id="L225" rel="#L225">225</span>
<span id="L226" rel="#L226">226</span>
<span id="L227" rel="#L227">227</span>
<span id="L228" rel="#L228">228</span>
<span id="L229" rel="#L229">229</span>
<span id="L230" rel="#L230">230</span>
<span id="L231" rel="#L231">231</span>
<span id="L232" rel="#L232">232</span>
<span id="L233" rel="#L233">233</span>
<span id="L234" rel="#L234">234</span>
<span id="L235" rel="#L235">235</span>
<span id="L236" rel="#L236">236</span>
<span id="L237" rel="#L237">237</span>
<span id="L238" rel="#L238">238</span>
<span id="L239" rel="#L239">239</span>
<span id="L240" rel="#L240">240</span>
<span id="L241" rel="#L241">241</span>
<span id="L242" rel="#L242">242</span>
<span id="L243" rel="#L243">243</span>
<span id="L244" rel="#L244">244</span>
<span id="L245" rel="#L245">245</span>
<span id="L246" rel="#L246">246</span>
<span id="L247" rel="#L247">247</span>
<span id="L248" rel="#L248">248</span>
<span id="L249" rel="#L249">249</span>
<span id="L250" rel="#L250">250</span>
<span id="L251" rel="#L251">251</span>
<span id="L252" rel="#L252">252</span>
<span id="L253" rel="#L253">253</span>
<span id="L254" rel="#L254">254</span>
<span id="L255" rel="#L255">255</span>
<span id="L256" rel="#L256">256</span>
<span id="L257" rel="#L257">257</span>
<span id="L258" rel="#L258">258</span>
<span id="L259" rel="#L259">259</span>
<span id="L260" rel="#L260">260</span>
<span id="L261" rel="#L261">261</span>
<span id="L262" rel="#L262">262</span>
<span id="L263" rel="#L263">263</span>
<span id="L264" rel="#L264">264</span>
<span id="L265" rel="#L265">265</span>
<span id="L266" rel="#L266">266</span>
<span id="L267" rel="#L267">267</span>
<span id="L268" rel="#L268">268</span>
<span id="L269" rel="#L269">269</span>
<span id="L270" rel="#L270">270</span>
<span id="L271" rel="#L271">271</span>
<span id="L272" rel="#L272">272</span>
<span id="L273" rel="#L273">273</span>
<span id="L274" rel="#L274">274</span>
<span id="L275" rel="#L275">275</span>
<span id="L276" rel="#L276">276</span>
<span id="L277" rel="#L277">277</span>
<span id="L278" rel="#L278">278</span>
<span id="L279" rel="#L279">279</span>
<span id="L280" rel="#L280">280</span>
<span id="L281" rel="#L281">281</span>
<span id="L282" rel="#L282">282</span>
<span id="L283" rel="#L283">283</span>
<span id="L284" rel="#L284">284</span>
<span id="L285" rel="#L285">285</span>
<span id="L286" rel="#L286">286</span>
<span id="L287" rel="#L287">287</span>
<span id="L288" rel="#L288">288</span>
<span id="L289" rel="#L289">289</span>
<span id="L290" rel="#L290">290</span>
<span id="L291" rel="#L291">291</span>
<span id="L292" rel="#L292">292</span>
<span id="L293" rel="#L293">293</span>
<span id="L294" rel="#L294">294</span>
<span id="L295" rel="#L295">295</span>
<span id="L296" rel="#L296">296</span>
<span id="L297" rel="#L297">297</span>
<span id="L298" rel="#L298">298</span>
<span id="L299" rel="#L299">299</span>
<span id="L300" rel="#L300">300</span>
<span id="L301" rel="#L301">301</span>
<span id="L302" rel="#L302">302</span>
<span id="L303" rel="#L303">303</span>
<span id="L304" rel="#L304">304</span>
<span id="L305" rel="#L305">305</span>
<span id="L306" rel="#L306">306</span>
<span id="L307" rel="#L307">307</span>
<span id="L308" rel="#L308">308</span>
<span id="L309" rel="#L309">309</span>
<span id="L310" rel="#L310">310</span>
<span id="L311" rel="#L311">311</span>
<span id="L312" rel="#L312">312</span>
<span id="L313" rel="#L313">313</span>
<span id="L314" rel="#L314">314</span>
<span id="L315" rel="#L315">315</span>
<span id="L316" rel="#L316">316</span>
<span id="L317" rel="#L317">317</span>
<span id="L318" rel="#L318">318</span>
<span id="L319" rel="#L319">319</span>
<span id="L320" rel="#L320">320</span>
<span id="L321" rel="#L321">321</span>
<span id="L322" rel="#L322">322</span>
<span id="L323" rel="#L323">323</span>
<span id="L324" rel="#L324">324</span>
<span id="L325" rel="#L325">325</span>
<span id="L326" rel="#L326">326</span>
<span id="L327" rel="#L327">327</span>
<span id="L328" rel="#L328">328</span>
<span id="L329" rel="#L329">329</span>
<span id="L330" rel="#L330">330</span>
<span id="L331" rel="#L331">331</span>
<span id="L332" rel="#L332">332</span>
<span id="L333" rel="#L333">333</span>
<span id="L334" rel="#L334">334</span>
<span id="L335" rel="#L335">335</span>
<span id="L336" rel="#L336">336</span>
<span id="L337" rel="#L337">337</span>
<span id="L338" rel="#L338">338</span>
<span id="L339" rel="#L339">339</span>
<span id="L340" rel="#L340">340</span>
<span id="L341" rel="#L341">341</span>
<span id="L342" rel="#L342">342</span>
<span id="L343" rel="#L343">343</span>
<span id="L344" rel="#L344">344</span>
<span id="L345" rel="#L345">345</span>
<span id="L346" rel="#L346">346</span>
<span id="L347" rel="#L347">347</span>
<span id="L348" rel="#L348">348</span>
<span id="L349" rel="#L349">349</span>
<span id="L350" rel="#L350">350</span>
<span id="L351" rel="#L351">351</span>
<span id="L352" rel="#L352">352</span>
<span id="L353" rel="#L353">353</span>
<span id="L354" rel="#L354">354</span>
<span id="L355" rel="#L355">355</span>
<span id="L356" rel="#L356">356</span>
<span id="L357" rel="#L357">357</span>
<span id="L358" rel="#L358">358</span>
<span id="L359" rel="#L359">359</span>
<span id="L360" rel="#L360">360</span>
<span id="L361" rel="#L361">361</span>
<span id="L362" rel="#L362">362</span>
<span id="L363" rel="#L363">363</span>
<span id="L364" rel="#L364">364</span>
<span id="L365" rel="#L365">365</span>
<span id="L366" rel="#L366">366</span>
<span id="L367" rel="#L367">367</span>
<span id="L368" rel="#L368">368</span>
<span id="L369" rel="#L369">369</span>
<span id="L370" rel="#L370">370</span>
<span id="L371" rel="#L371">371</span>
<span id="L372" rel="#L372">372</span>
<span id="L373" rel="#L373">373</span>
<span id="L374" rel="#L374">374</span>
<span id="L375" rel="#L375">375</span>
<span id="L376" rel="#L376">376</span>
<span id="L377" rel="#L377">377</span>
<span id="L378" rel="#L378">378</span>
<span id="L379" rel="#L379">379</span>
<span id="L380" rel="#L380">380</span>
<span id="L381" rel="#L381">381</span>
<span id="L382" rel="#L382">382</span>
<span id="L383" rel="#L383">383</span>
<span id="L384" rel="#L384">384</span>
<span id="L385" rel="#L385">385</span>
<span id="L386" rel="#L386">386</span>
<span id="L387" rel="#L387">387</span>
<span id="L388" rel="#L388">388</span>
<span id="L389" rel="#L389">389</span>
<span id="L390" rel="#L390">390</span>
<span id="L391" rel="#L391">391</span>
<span id="L392" rel="#L392">392</span>
<span id="L393" rel="#L393">393</span>
<span id="L394" rel="#L394">394</span>
<span id="L395" rel="#L395">395</span>
<span id="L396" rel="#L396">396</span>
<span id="L397" rel="#L397">397</span>
<span id="L398" rel="#L398">398</span>
<span id="L399" rel="#L399">399</span>
<span id="L400" rel="#L400">400</span>
<span id="L401" rel="#L401">401</span>
<span id="L402" rel="#L402">402</span>
<span id="L403" rel="#L403">403</span>
<span id="L404" rel="#L404">404</span>
<span id="L405" rel="#L405">405</span>
<span id="L406" rel="#L406">406</span>
<span id="L407" rel="#L407">407</span>
<span id="L408" rel="#L408">408</span>
<span id="L409" rel="#L409">409</span>
<span id="L410" rel="#L410">410</span>
<span id="L411" rel="#L411">411</span>
<span id="L412" rel="#L412">412</span>
<span id="L413" rel="#L413">413</span>
<span id="L414" rel="#L414">414</span>
<span id="L415" rel="#L415">415</span>
<span id="L416" rel="#L416">416</span>
<span id="L417" rel="#L417">417</span>
<span id="L418" rel="#L418">418</span>
<span id="L419" rel="#L419">419</span>
<span id="L420" rel="#L420">420</span>
<span id="L421" rel="#L421">421</span>
<span id="L422" rel="#L422">422</span>
<span id="L423" rel="#L423">423</span>
<span id="L424" rel="#L424">424</span>
<span id="L425" rel="#L425">425</span>
<span id="L426" rel="#L426">426</span>
<span id="L427" rel="#L427">427</span>
<span id="L428" rel="#L428">428</span>
<span id="L429" rel="#L429">429</span>
<span id="L430" rel="#L430">430</span>
<span id="L431" rel="#L431">431</span>
<span id="L432" rel="#L432">432</span>
<span id="L433" rel="#L433">433</span>
<span id="L434" rel="#L434">434</span>
<span id="L435" rel="#L435">435</span>
<span id="L436" rel="#L436">436</span>
<span id="L437" rel="#L437">437</span>
<span id="L438" rel="#L438">438</span>
<span id="L439" rel="#L439">439</span>
<span id="L440" rel="#L440">440</span>
<span id="L441" rel="#L441">441</span>
<span id="L442" rel="#L442">442</span>
<span id="L443" rel="#L443">443</span>
<span id="L444" rel="#L444">444</span>
<span id="L445" rel="#L445">445</span>
<span id="L446" rel="#L446">446</span>
<span id="L447" rel="#L447">447</span>
<span id="L448" rel="#L448">448</span>
<span id="L449" rel="#L449">449</span>
<span id="L450" rel="#L450">450</span>
<span id="L451" rel="#L451">451</span>
<span id="L452" rel="#L452">452</span>
<span id="L453" rel="#L453">453</span>
<span id="L454" rel="#L454">454</span>
<span id="L455" rel="#L455">455</span>
<span id="L456" rel="#L456">456</span>
<span id="L457" rel="#L457">457</span>
<span id="L458" rel="#L458">458</span>
<span id="L459" rel="#L459">459</span>
<span id="L460" rel="#L460">460</span>
<span id="L461" rel="#L461">461</span>
<span id="L462" rel="#L462">462</span>
<span id="L463" rel="#L463">463</span>
<span id="L464" rel="#L464">464</span>
<span id="L465" rel="#L465">465</span>
<span id="L466" rel="#L466">466</span>
<span id="L467" rel="#L467">467</span>
<span id="L468" rel="#L468">468</span>
<span id="L469" rel="#L469">469</span>
<span id="L470" rel="#L470">470</span>
<span id="L471" rel="#L471">471</span>
<span id="L472" rel="#L472">472</span>
<span id="L473" rel="#L473">473</span>
<span id="L474" rel="#L474">474</span>
<span id="L475" rel="#L475">475</span>
<span id="L476" rel="#L476">476</span>
<span id="L477" rel="#L477">477</span>
<span id="L478" rel="#L478">478</span>
<span id="L479" rel="#L479">479</span>
<span id="L480" rel="#L480">480</span>
<span id="L481" rel="#L481">481</span>
<span id="L482" rel="#L482">482</span>
<span id="L483" rel="#L483">483</span>
<span id="L484" rel="#L484">484</span>
<span id="L485" rel="#L485">485</span>
<span id="L486" rel="#L486">486</span>
<span id="L487" rel="#L487">487</span>
<span id="L488" rel="#L488">488</span>
<span id="L489" rel="#L489">489</span>
<span id="L490" rel="#L490">490</span>
<span id="L491" rel="#L491">491</span>
<span id="L492" rel="#L492">492</span>
<span id="L493" rel="#L493">493</span>
<span id="L494" rel="#L494">494</span>
<span id="L495" rel="#L495">495</span>
<span id="L496" rel="#L496">496</span>
<span id="L497" rel="#L497">497</span>
<span id="L498" rel="#L498">498</span>
<span id="L499" rel="#L499">499</span>
<span id="L500" rel="#L500">500</span>
<span id="L501" rel="#L501">501</span>
<span id="L502" rel="#L502">502</span>
<span id="L503" rel="#L503">503</span>
<span id="L504" rel="#L504">504</span>
<span id="L505" rel="#L505">505</span>
<span id="L506" rel="#L506">506</span>
<span id="L507" rel="#L507">507</span>
<span id="L508" rel="#L508">508</span>
<span id="L509" rel="#L509">509</span>
<span id="L510" rel="#L510">510</span>
<span id="L511" rel="#L511">511</span>
<span id="L512" rel="#L512">512</span>
<span id="L513" rel="#L513">513</span>
<span id="L514" rel="#L514">514</span>
<span id="L515" rel="#L515">515</span>
<span id="L516" rel="#L516">516</span>
<span id="L517" rel="#L517">517</span>
<span id="L518" rel="#L518">518</span>
<span id="L519" rel="#L519">519</span>
<span id="L520" rel="#L520">520</span>
<span id="L521" rel="#L521">521</span>
<span id="L522" rel="#L522">522</span>
<span id="L523" rel="#L523">523</span>
<span id="L524" rel="#L524">524</span>
<span id="L525" rel="#L525">525</span>
<span id="L526" rel="#L526">526</span>
<span id="L527" rel="#L527">527</span>
<span id="L528" rel="#L528">528</span>
<span id="L529" rel="#L529">529</span>
<span id="L530" rel="#L530">530</span>
<span id="L531" rel="#L531">531</span>
<span id="L532" rel="#L532">532</span>
<span id="L533" rel="#L533">533</span>
<span id="L534" rel="#L534">534</span>
<span id="L535" rel="#L535">535</span>
<span id="L536" rel="#L536">536</span>
<span id="L537" rel="#L537">537</span>
<span id="L538" rel="#L538">538</span>
<span id="L539" rel="#L539">539</span>
<span id="L540" rel="#L540">540</span>
<span id="L541" rel="#L541">541</span>
<span id="L542" rel="#L542">542</span>
<span id="L543" rel="#L543">543</span>
<span id="L544" rel="#L544">544</span>
<span id="L545" rel="#L545">545</span>
<span id="L546" rel="#L546">546</span>
<span id="L547" rel="#L547">547</span>
<span id="L548" rel="#L548">548</span>
<span id="L549" rel="#L549">549</span>
<span id="L550" rel="#L550">550</span>
<span id="L551" rel="#L551">551</span>
<span id="L552" rel="#L552">552</span>
<span id="L553" rel="#L553">553</span>
<span id="L554" rel="#L554">554</span>
<span id="L555" rel="#L555">555</span>
<span id="L556" rel="#L556">556</span>
<span id="L557" rel="#L557">557</span>
<span id="L558" rel="#L558">558</span>
<span id="L559" rel="#L559">559</span>
<span id="L560" rel="#L560">560</span>
<span id="L561" rel="#L561">561</span>
<span id="L562" rel="#L562">562</span>
<span id="L563" rel="#L563">563</span>
<span id="L564" rel="#L564">564</span>
<span id="L565" rel="#L565">565</span>
<span id="L566" rel="#L566">566</span>
<span id="L567" rel="#L567">567</span>
<span id="L568" rel="#L568">568</span>
<span id="L569" rel="#L569">569</span>
<span id="L570" rel="#L570">570</span>
<span id="L571" rel="#L571">571</span>
<span id="L572" rel="#L572">572</span>
<span id="L573" rel="#L573">573</span>
<span id="L574" rel="#L574">574</span>
<span id="L575" rel="#L575">575</span>
<span id="L576" rel="#L576">576</span>
<span id="L577" rel="#L577">577</span>
<span id="L578" rel="#L578">578</span>
<span id="L579" rel="#L579">579</span>
<span id="L580" rel="#L580">580</span>
<span id="L581" rel="#L581">581</span>
<span id="L582" rel="#L582">582</span>
<span id="L583" rel="#L583">583</span>
<span id="L584" rel="#L584">584</span>
<span id="L585" rel="#L585">585</span>
<span id="L586" rel="#L586">586</span>
<span id="L587" rel="#L587">587</span>
<span id="L588" rel="#L588">588</span>
<span id="L589" rel="#L589">589</span>
<span id="L590" rel="#L590">590</span>
<span id="L591" rel="#L591">591</span>
<span id="L592" rel="#L592">592</span>
<span id="L593" rel="#L593">593</span>
<span id="L594" rel="#L594">594</span>
<span id="L595" rel="#L595">595</span>
<span id="L596" rel="#L596">596</span>
<span id="L597" rel="#L597">597</span>
<span id="L598" rel="#L598">598</span>
<span id="L599" rel="#L599">599</span>
<span id="L600" rel="#L600">600</span>
<span id="L601" rel="#L601">601</span>
<span id="L602" rel="#L602">602</span>
<span id="L603" rel="#L603">603</span>
<span id="L604" rel="#L604">604</span>
<span id="L605" rel="#L605">605</span>
<span id="L606" rel="#L606">606</span>
<span id="L607" rel="#L607">607</span>
<span id="L608" rel="#L608">608</span>
<span id="L609" rel="#L609">609</span>
<span id="L610" rel="#L610">610</span>
<span id="L611" rel="#L611">611</span>
<span id="L612" rel="#L612">612</span>
<span id="L613" rel="#L613">613</span>
<span id="L614" rel="#L614">614</span>
<span id="L615" rel="#L615">615</span>
<span id="L616" rel="#L616">616</span>
<span id="L617" rel="#L617">617</span>
<span id="L618" rel="#L618">618</span>
<span id="L619" rel="#L619">619</span>
<span id="L620" rel="#L620">620</span>
<span id="L621" rel="#L621">621</span>
<span id="L622" rel="#L622">622</span>
<span id="L623" rel="#L623">623</span>
<span id="L624" rel="#L624">624</span>
<span id="L625" rel="#L625">625</span>
<span id="L626" rel="#L626">626</span>
<span id="L627" rel="#L627">627</span>
<span id="L628" rel="#L628">628</span>
<span id="L629" rel="#L629">629</span>
<span id="L630" rel="#L630">630</span>
<span id="L631" rel="#L631">631</span>
<span id="L632" rel="#L632">632</span>
<span id="L633" rel="#L633">633</span>
<span id="L634" rel="#L634">634</span>
<span id="L635" rel="#L635">635</span>
<span id="L636" rel="#L636">636</span>
<span id="L637" rel="#L637">637</span>
<span id="L638" rel="#L638">638</span>
<span id="L639" rel="#L639">639</span>
<span id="L640" rel="#L640">640</span>
<span id="L641" rel="#L641">641</span>
<span id="L642" rel="#L642">642</span>
<span id="L643" rel="#L643">643</span>
<span id="L644" rel="#L644">644</span>
<span id="L645" rel="#L645">645</span>
<span id="L646" rel="#L646">646</span>
<span id="L647" rel="#L647">647</span>
<span id="L648" rel="#L648">648</span>
<span id="L649" rel="#L649">649</span>
<span id="L650" rel="#L650">650</span>
<span id="L651" rel="#L651">651</span>
<span id="L652" rel="#L652">652</span>
<span id="L653" rel="#L653">653</span>
<span id="L654" rel="#L654">654</span>
<span id="L655" rel="#L655">655</span>
<span id="L656" rel="#L656">656</span>
<span id="L657" rel="#L657">657</span>
<span id="L658" rel="#L658">658</span>
<span id="L659" rel="#L659">659</span>

            </td>
            <td class="blob-line-code"><div class="code-body highlight"><pre><div class='line' id='LC1'><span class="c1">// To run:</span></div><div class='line' id='LC2'><span class="c1">//  g++ -O3 -o pifm pifm.c</span></div><div class='line' id='LC3'><span class="c1">//  ./pifm left_right.wav 103.3 22050 stereo</span></div><div class='line' id='LC4'><span class="c1">//  ./pifm sound.wav</span></div><div class='line' id='LC5'><br/></div><div class='line' id='LC6'><span class="c1">// Created by Oliver Mattos and Oskar Weigl.</span></div><div class='line' id='LC7'><span class="c1">// Code quality = Totally hacked together.</span></div><div class='line' id='LC8'><br/></div><div class='line' id='LC9'><br/></div><div class='line' id='LC10'><span class="cp">#include &lt;stdio.h&gt;</span></div><div class='line' id='LC11'><span class="cp">#include &lt;string.h&gt;</span></div><div class='line' id='LC12'><span class="cp">#include &lt;stdlib.h&gt;</span></div><div class='line' id='LC13'><span class="cp">#include &lt;dirent.h&gt;</span></div><div class='line' id='LC14'><span class="cp">#include &lt;math.h&gt;</span></div><div class='line' id='LC15'><span class="cp">#include &lt;fcntl.h&gt;</span></div><div class='line' id='LC16'><span class="cp">#include &lt;assert.h&gt;</span></div><div class='line' id='LC17'><span class="cp">#include &lt;malloc.h&gt;</span></div><div class='line' id='LC18'><span class="cp">#include &lt;sys/mman.h&gt;</span></div><div class='line' id='LC19'><span class="cp">#include &lt;sys/types.h&gt;</span></div><div class='line' id='LC20'><span class="cp">#include &lt;sys/stat.h&gt;</span></div><div class='line' id='LC21'><span class="cp">#include &lt;sys/time.h&gt;</span></div><div class='line' id='LC22'><span class="cp">#include &lt;signal.h&gt;</span></div><div class='line' id='LC23'><span class="cp">#include &lt;unistd.h&gt;</span></div><div class='line' id='LC24'><br/></div><div class='line' id='LC25'><span class="cp">#define PAGE_SIZE (4*1024)</span></div><div class='line' id='LC26'><span class="cp">#define BLOCK_SIZE (4*1024)</span></div><div class='line' id='LC27'><br/></div><div class='line' id='LC28'><span class="cp">#define PI 3.14159265</span></div><div class='line' id='LC29'><br/></div><div class='line' id='LC30'><span class="kt">int</span>  <span class="n">mem_fd</span><span class="p">;</span></div><div class='line' id='LC31'><span class="kt">char</span> <span class="o">*</span><span class="n">gpio_mem</span><span class="p">,</span> <span class="o">*</span><span class="n">gpio_map</span><span class="p">;</span></div><div class='line' id='LC32'><span class="kt">char</span> <span class="o">*</span><span class="n">spi0_mem</span><span class="p">,</span> <span class="o">*</span><span class="n">spi0_map</span><span class="p">;</span></div><div class='line' id='LC33'><br/></div><div class='line' id='LC34'><br/></div><div class='line' id='LC35'><span class="c1">// I/O access</span></div><div class='line' id='LC36'><span class="k">volatile</span> <span class="kt">unsigned</span> <span class="o">*</span><span class="n">gpio</span><span class="p">;</span></div><div class='line' id='LC37'><span class="k">volatile</span> <span class="kt">unsigned</span> <span class="o">*</span><span class="n">allof7e</span><span class="p">;</span></div><div class='line' id='LC38'><br/></div><div class='line' id='LC39'><span class="c1">// GPIO setup macros. Always use INP_GPIO(x) before using OUT_GPIO(x) or SET_GPIO_ALT(x,y)</span></div><div class='line' id='LC40'><span class="cp">#define INP_GPIO(g) *(gpio+((g)/10)) &amp;= ~(7&lt;&lt;(((g)%10)*3))</span></div><div class='line' id='LC41'><span class="cp">#define OUT_GPIO(g) *(gpio+((g)/10)) |=  (1&lt;&lt;(((g)%10)*3))</span></div><div class='line' id='LC42'><span class="cp">#define SET_GPIO_ALT(g,a) *(gpio+(((g)/10))) |= (((a)&lt;=3?(a)+4:(a)==4?3:2)&lt;&lt;(((g)%10)*3))</span></div><div class='line' id='LC43'><br/></div><div class='line' id='LC44'><span class="cp">#define GPIO_SET *(gpio+7)  </span><span class="c1">// sets   bits which are 1 ignores bits which are 0</span></div><div class='line' id='LC45'><span class="cp">#define GPIO_CLR *(gpio+10) </span><span class="c1">// clears bits which are 1 ignores bits which are 0</span></div><div class='line' id='LC46'><span class="cp">#define GPIO_GET *(gpio+13)  </span><span class="c1">// sets   bits which are 1 ignores bits which are 0</span></div><div class='line' id='LC47'><br/></div><div class='line' id='LC48'><span class="cp">#define ACCESS(base) *(volatile int*)((int)allof7e+base-0x7e000000)</span></div><div class='line' id='LC49'><span class="cp">#define SETBIT(base, bit) ACCESS(base) |= 1&lt;&lt;bit</span></div><div class='line' id='LC50'><span class="cp">#define CLRBIT(base, bit) ACCESS(base) &amp;= ~(1&lt;&lt;bit)</span></div><div class='line' id='LC51'><br/></div><div class='line' id='LC52'><span class="cp">#define CM_GP0CTL (0x7e101070)</span></div><div class='line' id='LC53'><span class="cp">#define GPFSEL0 (0x7E200000)</span></div><div class='line' id='LC54'><span class="cp">#define CM_GP0DIV (0x7e101074)</span></div><div class='line' id='LC55'><span class="cp">#define CLKBASE (0x7E101000)</span></div><div class='line' id='LC56'><span class="cp">#define DMABASE (0x7E007000)</span></div><div class='line' id='LC57'><span class="cp">#define PWMBASE  (0x7e20C000) </span><span class="cm">/* PWM controller */</span><span class="cp"></span></div><div class='line' id='LC58'><br/></div><div class='line' id='LC59'><br/></div><div class='line' id='LC60'><span class="k">struct</span> <span class="n">GPCTL</span> <span class="p">{</span></div><div class='line' id='LC61'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">char</span> <span class="n">SRC</span>         <span class="o">:</span> <span class="mi">4</span><span class="p">;</span></div><div class='line' id='LC62'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">char</span> <span class="n">ENAB</span>        <span class="o">:</span> <span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC63'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">char</span> <span class="n">KILL</span>        <span class="o">:</span> <span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC64'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">char</span>             <span class="o">:</span> <span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC65'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">char</span> <span class="n">BUSY</span>        <span class="o">:</span> <span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC66'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">char</span> <span class="n">FLIP</span>        <span class="o">:</span> <span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC67'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">char</span> <span class="n">MASH</span>        <span class="o">:</span> <span class="mi">2</span><span class="p">;</span></div><div class='line' id='LC68'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">unsigned</span> <span class="kt">int</span>     <span class="o">:</span> <span class="mi">13</span><span class="p">;</span></div><div class='line' id='LC69'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">char</span> <span class="n">PASSWD</span>      <span class="o">:</span> <span class="mi">8</span><span class="p">;</span></div><div class='line' id='LC70'><span class="p">};</span></div><div class='line' id='LC71'><br/></div><div class='line' id='LC72'><br/></div><div class='line' id='LC73'><br/></div><div class='line' id='LC74'><span class="kt">void</span> <span class="nf">getRealMemPage</span><span class="p">(</span><span class="kt">void</span><span class="o">**</span> <span class="n">vAddr</span><span class="p">,</span> <span class="kt">void</span><span class="o">**</span> <span class="n">pAddr</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC75'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">void</span><span class="o">*</span> <span class="n">a</span> <span class="o">=</span> <span class="n">valloc</span><span class="p">(</span><span class="mi">4096</span><span class="p">);</span></div><div class='line' id='LC76'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC77'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">((</span><span class="kt">int</span><span class="o">*</span><span class="p">)</span><span class="n">a</span><span class="p">)[</span><span class="mi">0</span><span class="p">]</span> <span class="o">=</span> <span class="mi">1</span><span class="p">;</span>  <span class="c1">// use page to force allocation.</span></div><div class='line' id='LC78'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC79'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">mlock</span><span class="p">(</span><span class="n">a</span><span class="p">,</span> <span class="mi">4096</span><span class="p">);</span>  <span class="c1">// lock into ram.</span></div><div class='line' id='LC80'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC81'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="o">*</span><span class="n">vAddr</span> <span class="o">=</span> <span class="n">a</span><span class="p">;</span>  <span class="c1">// yay - we know the virtual address</span></div><div class='line' id='LC82'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC83'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">unsigned</span> <span class="kt">long</span> <span class="kt">long</span> <span class="n">frameinfo</span><span class="p">;</span></div><div class='line' id='LC84'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC85'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">fp</span> <span class="o">=</span> <span class="n">open</span><span class="p">(</span><span class="s">&quot;/proc/self/pagemap&quot;</span><span class="p">,</span> <span class="sc">&#39;r&#39;</span><span class="p">);</span></div><div class='line' id='LC86'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">lseek</span><span class="p">(</span><span class="n">fp</span><span class="p">,</span> <span class="p">((</span><span class="kt">int</span><span class="p">)</span><span class="n">a</span><span class="p">)</span><span class="o">/</span><span class="mi">4096</span><span class="o">*</span><span class="mi">8</span><span class="p">,</span> <span class="n">SEEK_SET</span><span class="p">);</span></div><div class='line' id='LC87'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">read</span><span class="p">(</span><span class="n">fp</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">frameinfo</span><span class="p">,</span> <span class="k">sizeof</span><span class="p">(</span><span class="n">frameinfo</span><span class="p">));</span></div><div class='line' id='LC88'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC89'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="o">*</span><span class="n">pAddr</span> <span class="o">=</span> <span class="p">(</span><span class="kt">void</span><span class="o">*</span><span class="p">)((</span><span class="kt">int</span><span class="p">)(</span><span class="n">frameinfo</span><span class="o">*</span><span class="mi">4096</span><span class="p">));</span></div><div class='line' id='LC90'><span class="p">}</span></div><div class='line' id='LC91'><br/></div><div class='line' id='LC92'><span class="kt">void</span> <span class="nf">freeRealMemPage</span><span class="p">(</span><span class="kt">void</span><span class="o">*</span> <span class="n">vAddr</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC93'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC94'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">munlock</span><span class="p">(</span><span class="n">vAddr</span><span class="p">,</span> <span class="mi">4096</span><span class="p">);</span>  <span class="c1">// unlock ram.</span></div><div class='line' id='LC95'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC96'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">free</span><span class="p">(</span><span class="n">vAddr</span><span class="p">);</span></div><div class='line' id='LC97'><span class="p">}</span></div><div class='line' id='LC98'><br/></div><div class='line' id='LC99'><span class="kt">void</span> <span class="nf">setup_fm</span><span class="p">()</span></div><div class='line' id='LC100'><span class="p">{</span></div><div class='line' id='LC101'><br/></div><div class='line' id='LC102'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="cm">/* open /dev/mem */</span></div><div class='line' id='LC103'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">((</span><span class="n">mem_fd</span> <span class="o">=</span> <span class="n">open</span><span class="p">(</span><span class="s">&quot;/dev/mem&quot;</span><span class="p">,</span> <span class="n">O_RDWR</span><span class="o">|</span><span class="n">O_SYNC</span><span class="p">)</span> <span class="p">)</span> <span class="o">&lt;</span> <span class="mi">0</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC104'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">printf</span><span class="p">(</span><span class="s">&quot;can&#39;t open /dev/mem </span><span class="se">\n</span><span class="s">&quot;</span><span class="p">);</span></div><div class='line' id='LC105'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">exit</span> <span class="p">(</span><span class="o">-</span><span class="mi">1</span><span class="p">);</span></div><div class='line' id='LC106'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC107'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC108'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">allof7e</span> <span class="o">=</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="o">*</span><span class="p">)</span><span class="n">mmap</span><span class="p">(</span></div><div class='line' id='LC109'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="nb">NULL</span><span class="p">,</span></div><div class='line' id='LC110'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x01000000</span><span class="p">,</span>  <span class="c1">//len</span></div><div class='line' id='LC111'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">PROT_READ</span><span class="o">|</span><span class="n">PROT_WRITE</span><span class="p">,</span></div><div class='line' id='LC112'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">MAP_SHARED</span><span class="p">,</span></div><div class='line' id='LC113'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">mem_fd</span><span class="p">,</span></div><div class='line' id='LC114'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x20000000</span>  <span class="c1">//base</span></div><div class='line' id='LC115'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">);</span></div><div class='line' id='LC116'><br/></div><div class='line' id='LC117'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">((</span><span class="kt">int</span><span class="p">)</span><span class="n">allof7e</span><span class="o">==-</span><span class="mi">1</span><span class="p">)</span> <span class="n">exit</span><span class="p">(</span><span class="o">-</span><span class="mi">1</span><span class="p">);</span></div><div class='line' id='LC118'><br/></div><div class='line' id='LC119'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">SETBIT</span><span class="p">(</span><span class="n">GPFSEL0</span> <span class="p">,</span> <span class="mi">14</span><span class="p">);</span></div><div class='line' id='LC120'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CLRBIT</span><span class="p">(</span><span class="n">GPFSEL0</span> <span class="p">,</span> <span class="mi">13</span><span class="p">);</span></div><div class='line' id='LC121'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CLRBIT</span><span class="p">(</span><span class="n">GPFSEL0</span> <span class="p">,</span> <span class="mi">12</span><span class="p">);</span></div><div class='line' id='LC122'><br/></div><div class='line' id='LC123'>&nbsp;</div><div class='line' id='LC124'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">struct</span> <span class="n">GPCTL</span> <span class="n">setupword</span> <span class="o">=</span> <span class="p">{</span><span class="mi">6</span><span class="cm">/*SRC*/</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span><span class="mh">0x5a</span><span class="p">};</span></div><div class='line' id='LC125'><br/></div><div class='line' id='LC126'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ACCESS</span><span class="p">(</span><span class="n">CM_GP0CTL</span><span class="p">)</span> <span class="o">=</span> <span class="o">*</span><span class="p">((</span><span class="kt">int</span><span class="o">*</span><span class="p">)</span><span class="o">&amp;</span><span class="n">setupword</span><span class="p">);</span></div><div class='line' id='LC127'><span class="p">}</span></div><div class='line' id='LC128'><br/></div><div class='line' id='LC129'><br/></div><div class='line' id='LC130'><span class="kt">void</span> <span class="nf">modulate</span><span class="p">(</span><span class="kt">int</span> <span class="n">m</span><span class="p">)</span></div><div class='line' id='LC131'><span class="p">{</span></div><div class='line' id='LC132'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ACCESS</span><span class="p">(</span><span class="n">CM_GP0DIV</span><span class="p">)</span> <span class="o">=</span> <span class="p">(</span><span class="mh">0x5a</span> <span class="o">&lt;&lt;</span> <span class="mi">24</span><span class="p">)</span> <span class="o">+</span> <span class="mh">0x4d72</span> <span class="o">+</span> <span class="n">m</span><span class="p">;</span></div><div class='line' id='LC133'><span class="p">}</span></div><div class='line' id='LC134'><br/></div><div class='line' id='LC135'><span class="k">struct</span> <span class="n">CB</span> <span class="p">{</span></div><div class='line' id='LC136'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">volatile</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">TI</span><span class="p">;</span></div><div class='line' id='LC137'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">volatile</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">SOURCE_AD</span><span class="p">;</span></div><div class='line' id='LC138'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">volatile</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">DEST_AD</span><span class="p">;</span></div><div class='line' id='LC139'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">volatile</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">TXFR_LEN</span><span class="p">;</span></div><div class='line' id='LC140'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">volatile</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">STRIDE</span><span class="p">;</span></div><div class='line' id='LC141'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">volatile</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">NEXTCONBK</span><span class="p">;</span></div><div class='line' id='LC142'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">volatile</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">RES1</span><span class="p">;</span></div><div class='line' id='LC143'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">volatile</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">RES2</span><span class="p">;</span></div><div class='line' id='LC144'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC145'><span class="p">};</span></div><div class='line' id='LC146'><br/></div><div class='line' id='LC147'><span class="k">struct</span> <span class="n">DMAregs</span> <span class="p">{</span></div><div class='line' id='LC148'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">volatile</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">CS</span><span class="p">;</span></div><div class='line' id='LC149'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">volatile</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">CONBLK_AD</span><span class="p">;</span></div><div class='line' id='LC150'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">volatile</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">TI</span><span class="p">;</span></div><div class='line' id='LC151'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">volatile</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">SOURCE_AD</span><span class="p">;</span></div><div class='line' id='LC152'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">volatile</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">DEST_AD</span><span class="p">;</span></div><div class='line' id='LC153'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">volatile</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">TXFR_LEN</span><span class="p">;</span></div><div class='line' id='LC154'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">volatile</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">STRIDE</span><span class="p">;</span></div><div class='line' id='LC155'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">volatile</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">NEXTCONBK</span><span class="p">;</span></div><div class='line' id='LC156'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">volatile</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">DEBUG</span><span class="p">;</span></div><div class='line' id='LC157'><span class="p">};</span></div><div class='line' id='LC158'><br/></div><div class='line' id='LC159'><span class="k">struct</span> <span class="n">PageInfo</span> <span class="p">{</span></div><div class='line' id='LC160'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">void</span><span class="o">*</span> <span class="n">p</span><span class="p">;</span>  <span class="c1">// physical address</span></div><div class='line' id='LC161'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">void</span><span class="o">*</span> <span class="n">v</span><span class="p">;</span>   <span class="c1">// virtual address</span></div><div class='line' id='LC162'><span class="p">};</span></div><div class='line' id='LC163'><br/></div><div class='line' id='LC164'><span class="k">struct</span> <span class="n">PageInfo</span> <span class="n">constPage</span><span class="p">;</span>   </div><div class='line' id='LC165'><span class="k">struct</span> <span class="n">PageInfo</span> <span class="n">instrPage</span><span class="p">;</span></div><div class='line' id='LC166'><span class="cp">#define BUFFERINSTRUCTIONS 65536</span></div><div class='line' id='LC167'><span class="k">struct</span> <span class="n">PageInfo</span> <span class="n">instrs</span><span class="p">[</span><span class="n">BUFFERINSTRUCTIONS</span><span class="p">];</span></div><div class='line' id='LC168'><br/></div><div class='line' id='LC169'><br/></div><div class='line' id='LC170'><br/></div><div class='line' id='LC171'><span class="n">class</span> <span class="n">SampleSink</span><span class="p">{</span></div><div class='line' id='LC172'><span class="nl">public:</span></div><div class='line' id='LC173'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">virtual</span> <span class="kt">void</span> <span class="n">consume</span><span class="p">(</span><span class="kt">float</span><span class="o">*</span> <span class="n">data</span><span class="p">,</span> <span class="kt">int</span> <span class="n">dataLen</span><span class="p">){};</span>  <span class="c1">// floating point samples</span></div><div class='line' id='LC174'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">virtual</span> <span class="kt">void</span> <span class="nf">consume</span><span class="p">(</span><span class="kt">void</span><span class="o">*</span> <span class="n">data</span><span class="p">,</span> <span class="kt">int</span> <span class="n">dataLen</span><span class="p">){};</span>  <span class="c1">// raw data, len in bytes.</span></div><div class='line' id='LC175'><span class="p">};</span></div><div class='line' id='LC176'><br/></div><div class='line' id='LC177'><span class="n">class</span> <span class="n">Outputter</span> <span class="o">:</span> <span class="n">public</span> <span class="n">SampleSink</span> <span class="p">{</span></div><div class='line' id='LC178'><span class="nl">public:</span></div><div class='line' id='LC179'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">bufPtr</span><span class="p">;</span></div><div class='line' id='LC180'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">clocksPerSample</span><span class="p">;</span></div><div class='line' id='LC181'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">const</span> <span class="kt">int</span> <span class="n">sleeptime</span><span class="p">;</span></div><div class='line' id='LC182'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">fracerror</span><span class="p">;</span></div><div class='line' id='LC183'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">timeErr</span><span class="p">;</span></div><div class='line' id='LC184'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC185'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">Outputter</span><span class="p">(</span><span class="kt">float</span> <span class="n">rate</span><span class="p">)</span><span class="o">:</span></div><div class='line' id='LC186'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">sleeptime</span><span class="p">((</span><span class="kt">float</span><span class="p">)</span><span class="mf">1e6</span> <span class="o">*</span> <span class="n">BUFFERINSTRUCTIONS</span><span class="o">/</span><span class="mi">4</span><span class="o">/</span><span class="n">rate</span><span class="o">/</span><span class="mi">2</span><span class="p">),</span>   <span class="c1">// sleep time is half of the time to empty the buffer</span></div><div class='line' id='LC187'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">fracerror</span><span class="p">(</span><span class="mi">0</span><span class="p">),</span></div><div class='line' id='LC188'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">timeErr</span><span class="p">(</span><span class="mi">0</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC189'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">clocksPerSample</span> <span class="o">=</span> <span class="mf">22500.0</span> <span class="o">/</span> <span class="n">rate</span> <span class="o">*</span> <span class="mf">1373.5</span><span class="p">;</span>  <span class="c1">// for timing, determined by experiment</span></div><div class='line' id='LC190'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">bufPtr</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC191'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">};</span></div><div class='line' id='LC192'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">void</span> <span class="nf">consume</span><span class="p">(</span><span class="kt">float</span><span class="o">*</span> <span class="n">data</span><span class="p">,</span> <span class="kt">int</span> <span class="n">num</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC193'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span><span class="o">&lt;</span><span class="n">num</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC194'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">value</span> <span class="o">=</span> <span class="n">data</span><span class="p">[</span><span class="n">i</span><span class="p">]</span><span class="o">*</span><span class="mi">8</span><span class="p">;</span>  <span class="c1">// modulation index (AKA volume!)</span></div><div class='line' id='LC195'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC196'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// dump raw baseband data to stdout for audacity analysis.</span></div><div class='line' id='LC197'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//write(1, &amp;value, 4);</span></div><div class='line' id='LC198'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC199'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// debug code.  Replaces data with a set of tones.</span></div><div class='line' id='LC200'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//static int debugCount;</span></div><div class='line' id='LC201'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//debugCount++;</span></div><div class='line' id='LC202'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//value = (debugCount &amp; 0x1000)?0.5:0;  // two different tests</span></div><div class='line' id='LC203'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//value += 0.2 * ((debugCount &amp; 0x8)?1.0:-1.0);   // tone</span></div><div class='line' id='LC204'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//if (debugCount &amp; 0x2000) value = 0;   // silence </span></div><div class='line' id='LC205'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// end debug code</span></div><div class='line' id='LC206'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC207'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">value</span> <span class="o">+=</span> <span class="n">fracerror</span><span class="p">;</span>  <span class="c1">// error that couldn&#39;t be encoded from last time.</span></div><div class='line' id='LC208'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC209'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">intval</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)(</span><span class="n">round</span><span class="p">(</span><span class="n">value</span><span class="p">));</span>  <span class="c1">// integer component</span></div><div class='line' id='LC210'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">frac</span> <span class="o">=</span> <span class="p">(</span><span class="n">value</span> <span class="o">-</span> <span class="p">(</span><span class="kt">float</span><span class="p">)</span><span class="n">intval</span> <span class="o">+</span> <span class="mi">1</span><span class="p">)</span><span class="o">/</span><span class="mi">2</span><span class="p">;</span></div><div class='line' id='LC211'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">fracval</span> <span class="o">=</span> <span class="n">round</span><span class="p">(</span><span class="n">frac</span><span class="o">*</span><span class="n">clocksPerSample</span><span class="p">);</span> <span class="c1">// the fractional component</span></div><div class='line' id='LC212'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC213'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// we also record time error so that if one sample is output</span></div><div class='line' id='LC214'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// for slightly too long, the next sample will be shorter.</span></div><div class='line' id='LC215'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">timeErr</span> <span class="o">=</span> <span class="n">timeErr</span> <span class="o">-</span> <span class="kt">int</span><span class="p">(</span><span class="n">timeErr</span><span class="p">)</span> <span class="o">+</span> <span class="n">clocksPerSample</span><span class="p">;</span></div><div class='line' id='LC216'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC217'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">fracerror</span> <span class="o">=</span> <span class="p">(</span><span class="n">frac</span> <span class="o">-</span> <span class="p">(</span><span class="kt">float</span><span class="p">)</span><span class="n">fracval</span><span class="o">*</span><span class="p">(</span><span class="mf">1.0</span><span class="o">-</span><span class="mf">2.3</span><span class="o">/</span><span class="n">clocksPerSample</span><span class="p">)</span><span class="o">/</span><span class="n">clocksPerSample</span><span class="p">)</span><span class="o">*</span><span class="mi">2</span><span class="p">;</span>  <span class="c1">// error to feed back for delta sigma</span></div><div class='line' id='LC218'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC219'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// Note, the 2.3 constant is because our PWM isn&#39;t perfect.</span></div><div class='line' id='LC220'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// There is a finite time for the DMA controller to load a new value from memory,</span></div><div class='line' id='LC221'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// Therefore the width of each pulse we try to insert has a constant added to it.</span></div><div class='line' id='LC222'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// That constant is about 2.3 bytes written to the serializer, or about 18 cycles.  We use delta sigma</span></div><div class='line' id='LC223'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// to correct for this error and the pwm timing quantization error.</span></div><div class='line' id='LC224'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC225'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// To reduce noise, rather than just rounding to the nearest clock we can use, we PWM between</span></div><div class='line' id='LC226'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// the two nearest values.</span></div><div class='line' id='LC227'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC228'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// delay if necessary.  We can also print debug stuff here while not breaking timing.</span></div><div class='line' id='LC229'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">static</span> <span class="kt">int</span> <span class="n">time</span><span class="p">;</span></div><div class='line' id='LC230'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">time</span><span class="o">++</span><span class="p">;</span></div><div class='line' id='LC231'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC232'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">while</span><span class="p">(</span> <span class="p">(</span><span class="n">ACCESS</span><span class="p">(</span><span class="n">DMABASE</span> <span class="o">+</span> <span class="mh">0x04</span> <span class="cm">/* CurBlock*/</span><span class="p">)</span> <span class="o">&amp;</span> <span class="o">~</span> <span class="mh">0x7F</span><span class="p">)</span> <span class="o">==</span>  <span class="p">(</span><span class="kt">int</span><span class="p">)(</span><span class="n">instrs</span><span class="p">[</span><span class="n">bufPtr</span><span class="p">].</span><span class="n">p</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC233'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">usleep</span><span class="p">(</span><span class="n">sleeptime</span><span class="p">);</span>  <span class="c1">// are we anywhere in the next 4 instructions?</span></div><div class='line' id='LC234'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC235'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC236'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// Create DMA command to set clock controller to output FM signal for PWM &quot;LOW&quot; time.</span></div><div class='line' id='LC237'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">((</span><span class="k">struct</span> <span class="n">CB</span><span class="o">*</span><span class="p">)(</span><span class="n">instrs</span><span class="p">[</span><span class="n">bufPtr</span><span class="p">].</span><span class="n">v</span><span class="p">))</span><span class="o">-&gt;</span><span class="n">SOURCE_AD</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">constPage</span><span class="p">.</span><span class="n">p</span> <span class="o">+</span> <span class="mi">2048</span> <span class="o">+</span> <span class="n">intval</span><span class="o">*</span><span class="mi">4</span> <span class="o">-</span> <span class="mi">4</span> <span class="p">;</span></div><div class='line' id='LC238'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">bufPtr</span><span class="o">++</span><span class="p">;</span></div><div class='line' id='LC239'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC240'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// Create DMA command to delay using serializer module for suitable time.</span></div><div class='line' id='LC241'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">((</span><span class="k">struct</span> <span class="n">CB</span><span class="o">*</span><span class="p">)(</span><span class="n">instrs</span><span class="p">[</span><span class="n">bufPtr</span><span class="p">].</span><span class="n">v</span><span class="p">))</span><span class="o">-&gt;</span><span class="n">TXFR_LEN</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">timeErr</span><span class="o">-</span><span class="n">fracval</span><span class="p">;</span></div><div class='line' id='LC242'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">bufPtr</span><span class="o">++</span><span class="p">;</span></div><div class='line' id='LC243'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC244'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// Create DMA command to set clock controller to output FM signal for PWM &quot;HIGH&quot; time.</span></div><div class='line' id='LC245'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">((</span><span class="k">struct</span> <span class="n">CB</span><span class="o">*</span><span class="p">)(</span><span class="n">instrs</span><span class="p">[</span><span class="n">bufPtr</span><span class="p">].</span><span class="n">v</span><span class="p">))</span><span class="o">-&gt;</span><span class="n">SOURCE_AD</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">constPage</span><span class="p">.</span><span class="n">p</span> <span class="o">+</span> <span class="mi">2048</span> <span class="o">+</span> <span class="n">intval</span><span class="o">*</span><span class="mi">4</span> <span class="o">+</span> <span class="mi">4</span><span class="p">;</span></div><div class='line' id='LC246'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">bufPtr</span><span class="o">++</span><span class="p">;</span></div><div class='line' id='LC247'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC248'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// Create DMA command for more delay.</span></div><div class='line' id='LC249'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">((</span><span class="k">struct</span> <span class="n">CB</span><span class="o">*</span><span class="p">)(</span><span class="n">instrs</span><span class="p">[</span><span class="n">bufPtr</span><span class="p">].</span><span class="n">v</span><span class="p">))</span><span class="o">-&gt;</span><span class="n">TXFR_LEN</span> <span class="o">=</span> <span class="n">fracval</span><span class="p">;</span></div><div class='line' id='LC250'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">bufPtr</span><span class="o">=</span><span class="p">(</span><span class="n">bufPtr</span><span class="o">+</span><span class="mi">1</span><span class="p">)</span> <span class="o">%</span> <span class="p">(</span><span class="n">BUFFERINSTRUCTIONS</span><span class="p">);</span></div><div class='line' id='LC251'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC252'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC253'><span class="p">};</span></div><div class='line' id='LC254'><br/></div><div class='line' id='LC255'><span class="n">class</span> <span class="n">PreEmp</span> <span class="o">:</span> <span class="n">public</span> <span class="n">SampleSink</span> <span class="p">{</span></div><div class='line' id='LC256'><span class="nl">public:</span></div><div class='line' id='LC257'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">fmconstant</span><span class="p">;</span></div><div class='line' id='LC258'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">dataold</span><span class="p">;</span></div><div class='line' id='LC259'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">SampleSink</span><span class="o">*</span> <span class="n">next</span><span class="p">;</span></div><div class='line' id='LC260'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC261'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// this isn&#39;t the right filter...  But it&#39;s close...</span></div><div class='line' id='LC262'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// Something todo with a bilinear transform not being right...</span></div><div class='line' id='LC263'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">PreEmp</span><span class="p">(</span><span class="kt">float</span> <span class="n">rate</span><span class="p">,</span> <span class="n">SampleSink</span><span class="o">*</span> <span class="n">next</span><span class="p">)</span><span class="o">:</span> </div><div class='line' id='LC264'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">fmconstant</span><span class="p">(</span><span class="n">rate</span> <span class="o">*</span> <span class="mf">75.0e-6</span><span class="p">),</span> <span class="c1">// for pre-emphisis filter.  75us time constant</span></div><div class='line' id='LC265'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">dataold</span><span class="p">(</span><span class="mi">0</span><span class="p">),</span></div><div class='line' id='LC266'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">next</span><span class="p">(</span><span class="n">next</span><span class="p">)</span> <span class="p">{</span> <span class="p">};</span></div><div class='line' id='LC267'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC268'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC269'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">void</span> <span class="nf">consume</span><span class="p">(</span><span class="kt">float</span><span class="o">*</span> <span class="n">data</span><span class="p">,</span> <span class="kt">int</span> <span class="n">num</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC270'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span><span class="o">&lt;</span><span class="n">num</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC271'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">value</span> <span class="o">=</span> <span class="n">data</span><span class="p">[</span><span class="n">i</span><span class="p">];</span></div><div class='line' id='LC272'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC273'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">sample</span> <span class="o">=</span> <span class="n">value</span> <span class="o">+</span> <span class="p">(</span><span class="n">dataold</span><span class="o">-</span><span class="n">value</span><span class="p">)</span> <span class="o">/</span> <span class="p">(</span><span class="mi">1</span><span class="o">-</span><span class="n">fmconstant</span><span class="p">);</span>  <span class="c1">// fir of 1 + s tau</span></div><div class='line' id='LC274'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC275'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">next</span><span class="o">-&gt;</span><span class="n">consume</span><span class="p">(</span><span class="o">&amp;</span><span class="n">sample</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></div><div class='line' id='LC276'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC277'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">dataold</span> <span class="o">=</span> <span class="n">value</span><span class="p">;</span></div><div class='line' id='LC278'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC279'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC280'><span class="p">};</span></div><div class='line' id='LC281'><br/></div><div class='line' id='LC282'><br/></div><div class='line' id='LC283'><span class="n">class</span> <span class="n">Resamp</span> <span class="o">:</span> <span class="n">public</span> <span class="n">SampleSink</span> <span class="p">{</span></div><div class='line' id='LC284'><span class="nl">public:</span></div><div class='line' id='LC285'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">static</span> <span class="k">const</span> <span class="kt">int</span> <span class="n">QUALITY</span> <span class="o">=</span> <span class="mi">5</span><span class="p">;</span>    <span class="c1">// comp. complexity goes up linearly with this.</span></div><div class='line' id='LC286'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">static</span> <span class="k">const</span> <span class="kt">int</span> <span class="n">SQUALITY</span> <span class="o">=</span> <span class="mi">10</span><span class="p">;</span>  <span class="c1">// start time quality (defines max phase error of filter vs ram used &amp; cache thrashing)</span></div><div class='line' id='LC287'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">static</span> <span class="k">const</span> <span class="kt">int</span> <span class="n">BUFSIZE</span> <span class="o">=</span> <span class="mi">1000</span><span class="p">;</span></div><div class='line' id='LC288'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">dataOld</span><span class="p">[</span><span class="n">QUALITY</span><span class="p">];</span></div><div class='line' id='LC289'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">sincLUT</span><span class="p">[</span><span class="n">SQUALITY</span><span class="p">][</span><span class="n">QUALITY</span><span class="p">];</span> <span class="c1">// [startime][samplenum]</span></div><div class='line' id='LC290'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">ratio</span><span class="p">;</span></div><div class='line' id='LC291'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">outTimeLeft</span><span class="p">;</span></div><div class='line' id='LC292'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">outBuffer</span><span class="p">[</span><span class="n">BUFSIZE</span><span class="p">];</span></div><div class='line' id='LC293'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">outBufPtr</span><span class="p">;</span></div><div class='line' id='LC294'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">SampleSink</span><span class="o">*</span> <span class="n">next</span><span class="p">;</span></div><div class='line' id='LC295'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC296'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">Resamp</span><span class="p">(</span><span class="kt">float</span> <span class="n">rateIn</span><span class="p">,</span> <span class="kt">float</span> <span class="n">rateOut</span><span class="p">,</span> <span class="n">SampleSink</span><span class="o">*</span> <span class="n">next</span><span class="p">)</span><span class="o">:</span> </div><div class='line' id='LC297'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">outTimeLeft</span><span class="p">(</span><span class="mf">1.0</span><span class="p">),</span></div><div class='line' id='LC298'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">outBufPtr</span><span class="p">(</span><span class="mi">0</span><span class="p">),</span></div><div class='line' id='LC299'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ratio</span><span class="p">((</span><span class="kt">float</span><span class="p">)</span><span class="n">rateIn</span><span class="o">/</span><span class="p">(</span><span class="kt">float</span><span class="p">)</span><span class="n">rateOut</span><span class="p">),</span></div><div class='line' id='LC300'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">next</span><span class="p">(</span><span class="n">next</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC301'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC302'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span><span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span><span class="o">&lt;</span><span class="n">QUALITY</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span>  <span class="c1">// sample</span></div><div class='line' id='LC303'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span><span class="p">(</span><span class="kt">int</span> <span class="n">j</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">j</span><span class="o">&lt;</span><span class="n">SQUALITY</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span>  <span class="c1">// starttime</span></div><div class='line' id='LC304'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">x</span> <span class="o">=</span> <span class="n">PI</span> <span class="o">*</span> <span class="p">((</span><span class="kt">float</span><span class="p">)</span><span class="n">j</span><span class="o">/</span><span class="n">SQUALITY</span> <span class="o">+</span> <span class="p">(</span><span class="n">QUALITY</span><span class="o">-</span><span class="mi">1</span><span class="o">-</span><span class="n">i</span><span class="p">)</span> <span class="o">-</span> <span class="p">(</span><span class="n">QUALITY</span><span class="o">-</span><span class="mi">1</span><span class="p">)</span><span class="o">/</span><span class="mf">2.0</span><span class="p">);</span></div><div class='line' id='LC305'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">x</span><span class="o">==</span><span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC306'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">sincLUT</span><span class="p">[</span><span class="n">j</span><span class="p">][</span><span class="n">i</span><span class="p">]</span> <span class="o">=</span> <span class="mf">1.0</span><span class="p">;</span>  <span class="c1">// sin(0)/(0) == 1, says my limits therory</span></div><div class='line' id='LC307'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">else</span></div><div class='line' id='LC308'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">sincLUT</span><span class="p">[</span><span class="n">j</span><span class="p">][</span><span class="n">i</span><span class="p">]</span> <span class="o">=</span> <span class="n">sin</span><span class="p">(</span><span class="n">x</span><span class="p">)</span><span class="o">/</span><span class="n">x</span><span class="p">;</span>            </div><div class='line' id='LC309'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC310'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC311'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC312'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">};</span></div><div class='line' id='LC313'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC314'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC315'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">void</span> <span class="nf">consume</span><span class="p">(</span><span class="kt">float</span><span class="o">*</span> <span class="n">data</span><span class="p">,</span> <span class="kt">int</span> <span class="n">num</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC316'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span><span class="o">&lt;</span><span class="n">num</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC317'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// shift old data along</span></div><div class='line' id='LC318'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">j</span><span class="o">&lt;</span><span class="n">QUALITY</span><span class="o">-</span><span class="mi">1</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC319'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">dataOld</span><span class="p">[</span><span class="n">j</span><span class="p">]</span> <span class="o">=</span> <span class="n">dataOld</span><span class="p">[</span><span class="n">j</span><span class="o">+</span><span class="mi">1</span><span class="p">];</span></div><div class='line' id='LC320'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC321'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC322'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// put in new sample</span></div><div class='line' id='LC323'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">dataOld</span><span class="p">[</span><span class="n">QUALITY</span><span class="o">-</span><span class="mi">1</span><span class="p">]</span> <span class="o">=</span> <span class="n">data</span><span class="p">[</span><span class="n">i</span><span class="p">];</span></div><div class='line' id='LC324'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">outTimeLeft</span> <span class="o">-=</span> <span class="mf">1.0</span><span class="p">;</span></div><div class='line' id='LC325'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC326'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// go output this stuff!</span></div><div class='line' id='LC327'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">while</span> <span class="p">(</span><span class="n">outTimeLeft</span><span class="o">&lt;</span><span class="mf">1.0</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC328'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">outSample</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC329'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">lutNum</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)(</span><span class="n">outTimeLeft</span><span class="o">*</span><span class="n">SQUALITY</span><span class="p">);</span></div><div class='line' id='LC330'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">j</span><span class="o">&lt;</span><span class="n">QUALITY</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC331'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">outSample</span> <span class="o">+=</span> <span class="n">dataOld</span><span class="p">[</span><span class="n">j</span><span class="p">]</span> <span class="o">*</span> <span class="n">sincLUT</span><span class="p">[</span><span class="n">lutNum</span><span class="p">][</span><span class="n">j</span><span class="p">];</span></div><div class='line' id='LC332'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC333'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">outBuffer</span><span class="p">[</span><span class="n">outBufPtr</span><span class="o">++</span><span class="p">]</span> <span class="o">=</span> <span class="n">outSample</span><span class="p">;</span></div><div class='line' id='LC334'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">outTimeLeft</span> <span class="o">+=</span> <span class="n">ratio</span><span class="p">;</span></div><div class='line' id='LC335'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC336'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// if we have lots of data, shunt it to the next stage.</span></div><div class='line' id='LC337'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">outBufPtr</span> <span class="o">&gt;=</span> <span class="n">BUFSIZE</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC338'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">next</span><span class="o">-&gt;</span><span class="n">consume</span><span class="p">(</span><span class="n">outBuffer</span><span class="p">,</span> <span class="n">outBufPtr</span><span class="p">);</span></div><div class='line' id='LC339'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">outBufPtr</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC340'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC341'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC342'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC343'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC344'><span class="p">};</span></div><div class='line' id='LC345'><br/></div><div class='line' id='LC346'><span class="n">class</span> <span class="n">NullSink</span><span class="o">:</span> <span class="n">public</span> <span class="n">SampleSink</span> <span class="p">{</span></div><div class='line' id='LC347'><span class="nl">public:</span></div><div class='line' id='LC348'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC349'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">NullSink</span><span class="p">()</span> <span class="p">{</span> <span class="p">}</span></div><div class='line' id='LC350'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC351'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">void</span> <span class="n">consume</span><span class="p">(</span><span class="kt">float</span><span class="o">*</span> <span class="n">data</span><span class="p">,</span> <span class="kt">int</span> <span class="n">num</span><span class="p">)</span> <span class="p">{}</span>   <span class="c1">// throws away data</span></div><div class='line' id='LC352'><span class="p">};</span></div><div class='line' id='LC353'><br/></div><div class='line' id='LC354'><span class="c1">// decodes a mono wav file</span></div><div class='line' id='LC355'><span class="n">class</span> <span class="n">Mono</span><span class="o">:</span> <span class="n">public</span> <span class="n">SampleSink</span> <span class="p">{</span></div><div class='line' id='LC356'><span class="nl">public:</span></div><div class='line' id='LC357'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">SampleSink</span><span class="o">*</span> <span class="n">next</span><span class="p">;</span></div><div class='line' id='LC358'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC359'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">Mono</span><span class="p">(</span><span class="n">SampleSink</span><span class="o">*</span> <span class="n">next</span><span class="p">)</span><span class="o">:</span> <span class="n">next</span><span class="p">(</span><span class="n">next</span><span class="p">)</span> <span class="p">{</span> <span class="p">}</span></div><div class='line' id='LC360'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC361'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">void</span> <span class="n">consume</span><span class="p">(</span><span class="kt">void</span><span class="o">*</span> <span class="n">data</span><span class="p">,</span> <span class="kt">int</span> <span class="n">num</span><span class="p">)</span> <span class="p">{</span>    <span class="c1">// expects num%2 == 0</span></div><div class='line' id='LC362'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span><span class="o">&lt;</span><span class="n">num</span><span class="o">/</span><span class="mi">2</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC363'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">l</span> <span class="o">=</span> <span class="p">(</span><span class="kt">float</span><span class="p">)(((</span><span class="kt">short</span><span class="o">*</span><span class="p">)</span><span class="n">data</span><span class="p">)[</span><span class="n">i</span><span class="p">])</span> <span class="o">/</span> <span class="mf">32768.0</span><span class="p">;</span></div><div class='line' id='LC364'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">next</span><span class="o">-&gt;</span><span class="n">consume</span><span class="p">(</span> <span class="o">&amp;</span><span class="n">l</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></div><div class='line' id='LC365'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC366'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC367'><span class="p">};</span></div><div class='line' id='LC368'><br/></div><div class='line' id='LC369'><span class="n">class</span> <span class="n">StereoSplitter</span><span class="o">:</span> <span class="n">public</span> <span class="n">SampleSink</span> <span class="p">{</span></div><div class='line' id='LC370'><span class="nl">public:</span></div><div class='line' id='LC371'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">SampleSink</span><span class="o">*</span> <span class="n">nextLeft</span><span class="p">;</span></div><div class='line' id='LC372'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">SampleSink</span><span class="o">*</span> <span class="n">nextRight</span><span class="p">;</span></div><div class='line' id='LC373'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC374'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">StereoSplitter</span><span class="p">(</span><span class="n">SampleSink</span><span class="o">*</span> <span class="n">nextLeft</span><span class="p">,</span> <span class="n">SampleSink</span><span class="o">*</span> <span class="n">nextRight</span><span class="p">)</span><span class="o">:</span> </div><div class='line' id='LC375'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">nextLeft</span><span class="p">(</span><span class="n">nextLeft</span><span class="p">),</span> <span class="n">nextRight</span><span class="p">(</span><span class="n">nextRight</span><span class="p">)</span> <span class="p">{</span> <span class="p">}</span></div><div class='line' id='LC376'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC377'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC378'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">void</span> <span class="n">consume</span><span class="p">(</span><span class="kt">void</span><span class="o">*</span> <span class="n">data</span><span class="p">,</span> <span class="kt">int</span> <span class="n">num</span><span class="p">)</span> <span class="p">{</span>    <span class="c1">// expects num%4 == 0</span></div><div class='line' id='LC379'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span><span class="o">&lt;</span><span class="n">num</span><span class="o">/</span><span class="mi">2</span><span class="p">;</span> <span class="n">i</span><span class="o">+=</span><span class="mi">2</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC380'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">l</span> <span class="o">=</span> <span class="p">(</span><span class="kt">float</span><span class="p">)(((</span><span class="kt">short</span><span class="o">*</span><span class="p">)</span><span class="n">data</span><span class="p">)[</span><span class="n">i</span><span class="p">])</span> <span class="o">/</span> <span class="mf">32768.0</span><span class="p">;</span></div><div class='line' id='LC381'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">nextLeft</span><span class="o">-&gt;</span><span class="n">consume</span><span class="p">(</span> <span class="o">&amp;</span><span class="n">l</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></div><div class='line' id='LC382'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC383'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">r</span> <span class="o">=</span> <span class="p">(</span><span class="kt">float</span><span class="p">)(((</span><span class="kt">short</span><span class="o">*</span><span class="p">)</span><span class="n">data</span><span class="p">)[</span><span class="n">i</span><span class="o">+</span><span class="mi">1</span><span class="p">])</span> <span class="o">/</span> <span class="mf">32768.0</span><span class="p">;</span></div><div class='line' id='LC384'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">nextRight</span><span class="o">-&gt;</span><span class="n">consume</span><span class="p">(</span> <span class="o">&amp;</span><span class="n">r</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></div><div class='line' id='LC385'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC386'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC387'><span class="p">};</span></div><div class='line' id='LC388'><br/></div><div class='line' id='LC389'><br/></div><div class='line' id='LC390'><span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">RDSDATA</span><span class="p">[]</span> <span class="o">=</span> <span class="p">{</span></div><div class='line' id='LC391'><span class="c1">// RDS data.  Send MSB first.  Google search gr_rds_data_encoder.cc to make your own data.</span></div><div class='line' id='LC392'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x01</span><span class="p">,</span> <span class="mh">0x02</span><span class="p">,</span> <span class="mh">0x1E</span><span class="p">,</span> <span class="mh">0xB0</span><span class="p">,</span> <span class="mh">0x00</span><span class="p">,</span> <span class="mh">0x05</span><span class="p">,</span> <span class="mh">0xA1</span><span class="p">,</span> <span class="mh">0x41</span><span class="p">,</span> <span class="mh">0xA4</span><span class="p">,</span> <span class="mh">0x12</span><span class="p">,</span> </div><div class='line' id='LC393'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x01</span><span class="p">,</span> <span class="mh">0x02</span><span class="p">,</span> <span class="mh">0x45</span><span class="p">,</span> <span class="mh">0x20</span><span class="p">,</span> <span class="mh">0x00</span><span class="p">,</span> <span class="mh">0x05</span><span class="p">,</span> <span class="mh">0xA1</span><span class="p">,</span> <span class="mh">0x19</span><span class="p">,</span> <span class="mh">0xB6</span><span class="p">,</span> <span class="mh">0x8C</span><span class="p">,</span> </div><div class='line' id='LC394'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x01</span><span class="p">,</span> <span class="mh">0x02</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x90</span><span class="p">,</span> <span class="mh">0x00</span><span class="p">,</span> <span class="mh">0x05</span><span class="p">,</span> <span class="mh">0xA0</span><span class="p">,</span> <span class="mh">0x80</span><span class="p">,</span> <span class="mh">0x80</span><span class="p">,</span> <span class="mh">0xDC</span><span class="p">,</span> </div><div class='line' id='LC395'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x01</span><span class="p">,</span> <span class="mh">0x03</span><span class="p">,</span> <span class="mh">0xC7</span><span class="p">,</span> <span class="mh">0xD0</span><span class="p">,</span> <span class="mh">0x00</span><span class="p">,</span> <span class="mh">0x05</span><span class="p">,</span> <span class="mh">0xA0</span><span class="p">,</span> <span class="mh">0x80</span><span class="p">,</span> <span class="mh">0x80</span><span class="p">,</span> <span class="mh">0xDC</span><span class="p">,</span> </div><div class='line' id='LC396'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x09</span><span class="p">,</span> <span class="mh">0x00</span><span class="p">,</span> <span class="mh">0x14</span><span class="p">,</span> <span class="mh">0x75</span><span class="p">,</span> <span class="mh">0x47</span><span class="p">,</span> <span class="mh">0x51</span><span class="p">,</span> <span class="mh">0x7D</span><span class="p">,</span> <span class="mh">0xB9</span><span class="p">,</span> <span class="mh">0x95</span><span class="p">,</span> <span class="mh">0x79</span><span class="p">,</span> </div><div class='line' id='LC397'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x09</span><span class="p">,</span> <span class="mh">0x00</span><span class="p">,</span> <span class="mh">0x4F</span><span class="p">,</span> <span class="mh">0xE7</span><span class="p">,</span> <span class="mh">0x32</span><span class="p">,</span> <span class="mh">0x02</span><span class="p">,</span> <span class="mh">0x21</span><span class="p">,</span> <span class="mh">0x99</span><span class="p">,</span> <span class="mh">0xC8</span><span class="p">,</span> <span class="mh">0x09</span><span class="p">,</span> </div><div class='line' id='LC398'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x09</span><span class="p">,</span> <span class="mh">0x00</span><span class="p">,</span> <span class="mh">0xA3</span><span class="p">,</span> <span class="mh">0x56</span><span class="p">,</span> <span class="mh">0xF6</span><span class="p">,</span> <span class="mh">0xD9</span><span class="p">,</span> <span class="mh">0xE8</span><span class="p">,</span> <span class="mh">0x81</span><span class="p">,</span> <span class="mh">0xE5</span><span class="p">,</span> <span class="mh">0xEE</span><span class="p">,</span> </div><div class='line' id='LC399'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x09</span><span class="p">,</span> <span class="mh">0x00</span><span class="p">,</span> <span class="mh">0xF8</span><span class="p">,</span> <span class="mh">0xC6</span><span class="p">,</span> <span class="mh">0xF7</span><span class="p">,</span> <span class="mh">0x5B</span><span class="p">,</span> <span class="mh">0x19</span><span class="p">,</span> <span class="mh">0xC8</span><span class="p">,</span> <span class="mh">0x80</span><span class="p">,</span> <span class="mh">0x88</span><span class="p">,</span> </div><div class='line' id='LC400'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x09</span><span class="p">,</span> <span class="mh">0x01</span><span class="p">,</span> <span class="mh">0x21</span><span class="p">,</span> <span class="mh">0xA5</span><span class="p">,</span> <span class="mh">0x26</span><span class="p">,</span> <span class="mh">0x19</span><span class="p">,</span> <span class="mh">0xD5</span><span class="p">,</span> <span class="mh">0xCD</span><span class="p">,</span> <span class="mh">0xC3</span><span class="p">,</span> <span class="mh">0xDC</span><span class="p">,</span> </div><div class='line' id='LC401'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x09</span><span class="p">,</span> <span class="mh">0x01</span><span class="p">,</span> <span class="mh">0x7A</span><span class="p">,</span> <span class="mh">0x36</span><span class="p">,</span> <span class="mh">0x26</span><span class="p">,</span> <span class="mh">0x56</span><span class="p">,</span> <span class="mh">0x31</span><span class="p">,</span> <span class="mh">0xC9</span><span class="p">,</span> <span class="mh">0xC8</span><span class="p">,</span> <span class="mh">0x72</span><span class="p">,</span> </div><div class='line' id='LC402'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x09</span><span class="p">,</span> <span class="mh">0x01</span><span class="p">,</span> <span class="mh">0x96</span><span class="p">,</span> <span class="mh">0x87</span><span class="p">,</span> <span class="mh">0x92</span><span class="p">,</span> <span class="mh">0x09</span><span class="p">,</span> <span class="mh">0xA5</span><span class="p">,</span> <span class="mh">0x41</span><span class="p">,</span> <span class="mh">0xA4</span><span class="p">,</span> <span class="mh">0x12</span><span class="p">,</span> </div><div class='line' id='LC403'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x09</span><span class="p">,</span> <span class="mh">0x01</span><span class="p">,</span> <span class="mh">0xCD</span><span class="p">,</span> <span class="mh">0x12</span><span class="p">,</span> <span class="mh">0x02</span><span class="p">,</span> <span class="mh">0x8C</span><span class="p">,</span> <span class="mh">0x0D</span><span class="p">,</span> <span class="mh">0xBD</span><span class="p">,</span> <span class="mh">0xB6</span><span class="p">,</span> <span class="mh">0xA6</span><span class="p">,</span> </div><div class='line' id='LC404'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x09</span><span class="p">,</span> <span class="mh">0x02</span><span class="p">,</span> <span class="mh">0x24</span><span class="p">,</span> <span class="mh">0x46</span><span class="p">,</span> <span class="mh">0x17</span><span class="p">,</span> <span class="mh">0x4B</span><span class="p">,</span> <span class="mh">0xB9</span><span class="p">,</span> <span class="mh">0xD1</span><span class="p">,</span> <span class="mh">0xBC</span><span class="p">,</span> <span class="mh">0xE2</span><span class="p">,</span> </div><div class='line' id='LC405'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x09</span><span class="p">,</span> <span class="mh">0x02</span><span class="p">,</span> <span class="mh">0x7F</span><span class="p">,</span> <span class="mh">0xD7</span><span class="p">,</span> <span class="mh">0x34</span><span class="p">,</span> <span class="mh">0x09</span><span class="p">,</span> <span class="mh">0xE1</span><span class="p">,</span> <span class="mh">0x9D</span><span class="p">,</span> <span class="mh">0xB5</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> </div><div class='line' id='LC406'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x09</span><span class="p">,</span> <span class="mh">0x02</span><span class="p">,</span> <span class="mh">0x93</span><span class="p">,</span> <span class="mh">0x66</span><span class="p">,</span> <span class="mh">0x16</span><span class="p">,</span> <span class="mh">0x92</span><span class="p">,</span> <span class="mh">0xD9</span><span class="p">,</span> <span class="mh">0xB0</span><span class="p">,</span> <span class="mh">0xB9</span><span class="p">,</span> <span class="mh">0x3E</span><span class="p">,</span> </div><div class='line' id='LC407'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x09</span><span class="p">,</span> <span class="mh">0x02</span><span class="p">,</span> <span class="mh">0xC8</span><span class="p">,</span> <span class="mh">0xF6</span><span class="p">,</span> <span class="mh">0x36</span><span class="p">,</span> <span class="mh">0xF4</span><span class="p">,</span> <span class="mh">0x85</span><span class="p">,</span> <span class="mh">0xB4</span><span class="p">,</span> <span class="mh">0xA4</span><span class="p">,</span> <span class="mh">0x74</span><span class="p">,</span> </div><div class='line' id='LC408'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x09</span><span class="p">,</span> <span class="mh">0x03</span><span class="p">,</span> <span class="mh">0x11</span><span class="p">,</span> <span class="mh">0x92</span><span class="p">,</span> <span class="mh">0x02</span><span class="p">,</span> <span class="mh">0x00</span><span class="p">,</span> <span class="mh">0x00</span><span class="p">,</span> <span class="mh">0x80</span><span class="p">,</span> <span class="mh">0x80</span><span class="p">,</span> <span class="mh">0xDC</span><span class="p">,</span> </div><div class='line' id='LC409'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x09</span><span class="p">,</span> <span class="mh">0x03</span><span class="p">,</span> <span class="mh">0x4A</span><span class="p">,</span> <span class="mh">0x02</span><span class="p">,</span> <span class="mh">0x02</span><span class="p">,</span> <span class="mh">0x00</span><span class="p">,</span> <span class="mh">0x00</span><span class="p">,</span> <span class="mh">0x80</span><span class="p">,</span> <span class="mh">0x80</span><span class="p">,</span> <span class="mh">0xDC</span><span class="p">,</span> </div><div class='line' id='LC410'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x09</span><span class="p">,</span> <span class="mh">0x03</span><span class="p">,</span> <span class="mh">0xA6</span><span class="p">,</span> <span class="mh">0xB2</span><span class="p">,</span> <span class="mh">0x02</span><span class="p">,</span> <span class="mh">0x00</span><span class="p">,</span> <span class="mh">0x00</span><span class="p">,</span> <span class="mh">0x80</span><span class="p">,</span> <span class="mh">0x80</span><span class="p">,</span> <span class="mh">0xDC</span><span class="p">,</span> </div><div class='line' id='LC411'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="mh">0x50</span><span class="p">,</span> <span class="mh">0xFF</span><span class="p">,</span> <span class="mh">0xA9</span><span class="p">,</span> <span class="mh">0x09</span><span class="p">,</span> <span class="mh">0x03</span><span class="p">,</span> <span class="mh">0xFD</span><span class="p">,</span> <span class="mh">0x22</span><span class="p">,</span> <span class="mh">0x02</span><span class="p">,</span> <span class="mh">0x00</span><span class="p">,</span> <span class="mh">0x00</span><span class="p">,</span> <span class="mh">0x80</span><span class="p">,</span> <span class="mh">0x80</span><span class="p">,</span> <span class="mh">0xDC</span></div><div class='line' id='LC412'><span class="p">};</span></div><div class='line' id='LC413'><br/></div><div class='line' id='LC414'><span class="n">class</span> <span class="n">RDSEncoder</span><span class="o">:</span> <span class="n">public</span> <span class="n">SampleSink</span> <span class="p">{</span></div><div class='line' id='LC415'><span class="nl">public:</span></div><div class='line' id='LC416'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">sinLut</span><span class="p">[</span><span class="mi">8</span><span class="p">];</span></div><div class='line' id='LC417'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">SampleSink</span><span class="o">*</span> <span class="n">next</span><span class="p">;</span></div><div class='line' id='LC418'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">bitNum</span><span class="p">;</span></div><div class='line' id='LC419'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">lastBit</span><span class="p">;</span></div><div class='line' id='LC420'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">time</span><span class="p">;</span></div><div class='line' id='LC421'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">lastValue</span><span class="p">;</span></div><div class='line' id='LC422'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC423'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">RDSEncoder</span><span class="p">(</span><span class="n">SampleSink</span><span class="o">*</span> <span class="n">next</span><span class="p">)</span><span class="o">:</span> </div><div class='line' id='LC424'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">next</span><span class="p">(</span><span class="n">next</span><span class="p">),</span> <span class="n">bitNum</span><span class="p">(</span><span class="mi">0</span><span class="p">),</span> <span class="n">lastBit</span><span class="p">(</span><span class="mi">0</span><span class="p">),</span> <span class="n">time</span><span class="p">(</span><span class="mi">0</span><span class="p">),</span> <span class="n">lastValue</span><span class="p">(</span><span class="mi">0</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC425'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span><span class="o">&lt;</span><span class="mi">8</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC426'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">sinLut</span><span class="p">[</span><span class="n">i</span><span class="p">]</span> <span class="o">=</span> <span class="n">sin</span><span class="p">((</span><span class="kt">float</span><span class="p">)</span><span class="n">i</span><span class="o">*</span><span class="mf">2.0</span><span class="o">*</span><span class="n">PI</span><span class="o">*</span><span class="mi">3</span><span class="o">/</span><span class="mi">8</span><span class="p">);</span></div><div class='line' id='LC427'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC428'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC429'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC430'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">void</span> <span class="n">consume</span><span class="p">(</span><span class="kt">float</span><span class="o">*</span> <span class="n">data</span><span class="p">,</span> <span class="kt">int</span> <span class="n">num</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC431'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span><span class="o">&lt;</span><span class="n">num</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC432'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">time</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC433'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// time for a new bit</span></div><div class='line' id='LC434'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">newBit</span> <span class="o">=</span> <span class="p">(</span><span class="n">RDSDATA</span><span class="p">[</span><span class="n">bitNum</span><span class="o">/</span><span class="mi">8</span><span class="p">]</span><span class="o">&gt;&gt;</span><span class="p">(</span><span class="mi">7</span><span class="o">-</span><span class="p">(</span><span class="n">bitNum</span><span class="o">%</span><span class="mi">8</span><span class="p">)))</span><span class="o">&amp;</span><span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC435'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">lastBit</span> <span class="o">=</span> <span class="n">lastBit</span><span class="o">^</span><span class="n">newBit</span><span class="p">;</span>  <span class="c1">// differential encoding</span></div><div class='line' id='LC436'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC437'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">bitNum</span> <span class="o">=</span> <span class="p">(</span><span class="n">bitNum</span><span class="o">+</span><span class="mi">1</span><span class="p">)</span><span class="o">%</span><span class="p">(</span><span class="mi">20</span><span class="o">*</span><span class="mi">13</span><span class="o">*</span><span class="mi">8</span><span class="p">);</span></div><div class='line' id='LC438'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC439'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC440'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">outputBit</span> <span class="o">=</span> <span class="p">(</span><span class="n">time</span><span class="o">&lt;</span><span class="mi">192</span><span class="p">)</span><span class="o">?</span><span class="n">lastBit</span><span class="o">:</span><span class="mi">1</span><span class="o">-</span><span class="n">lastBit</span><span class="p">;</span> <span class="c1">// manchester encoding</span></div><div class='line' id='LC441'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC442'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">lastValue</span> <span class="o">=</span> <span class="n">lastValue</span><span class="o">*</span><span class="mf">0.99</span> <span class="o">+</span> <span class="p">(((</span><span class="kt">float</span><span class="p">)</span><span class="n">outputBit</span><span class="p">)</span><span class="o">*</span><span class="mi">2</span><span class="o">-</span><span class="mi">1</span><span class="p">)</span><span class="o">*</span><span class="mf">0.01</span><span class="p">;</span>  <span class="c1">// very simple IIR filter to hopefully reduce sidebands.</span></div><div class='line' id='LC443'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">data</span><span class="p">[</span><span class="n">i</span><span class="p">]</span> <span class="o">+=</span> <span class="n">lastValue</span><span class="o">*</span><span class="n">sinLut</span><span class="p">[</span><span class="n">time</span><span class="o">%</span><span class="mi">8</span><span class="p">]</span><span class="o">*</span><span class="mf">0.05</span><span class="p">;</span></div><div class='line' id='LC444'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC445'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">time</span> <span class="o">=</span> <span class="p">(</span><span class="n">time</span><span class="o">+</span><span class="mi">1</span><span class="p">)</span><span class="o">%</span><span class="mi">384</span><span class="p">;</span></div><div class='line' id='LC446'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC447'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">next</span><span class="o">-&gt;</span><span class="n">consume</span><span class="p">(</span><span class="n">data</span><span class="p">,</span> <span class="n">num</span><span class="p">);</span></div><div class='line' id='LC448'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC449'><span class="p">};</span></div><div class='line' id='LC450'><br/></div><div class='line' id='LC451'><span class="c1">// Takes 2 input signals at 152kHz and stereo modulates it.</span></div><div class='line' id='LC452'><span class="n">class</span> <span class="n">StereoModulator</span><span class="o">:</span> <span class="n">public</span> <span class="n">SampleSink</span> <span class="p">{</span></div><div class='line' id='LC453'><span class="nl">public:</span></div><div class='line' id='LC454'><br/></div><div class='line' id='LC455'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// Helper to make two input interfaces for the stereomodulator.   Feels like I&#39;m reimplementing a closure here... :-(</span></div><div class='line' id='LC456'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">class</span> <span class="n">ModulatorInput</span><span class="o">:</span> <span class="n">public</span> <span class="n">SampleSink</span> <span class="p">{</span></div><div class='line' id='LC457'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="nl">public:</span></div><div class='line' id='LC458'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">StereoModulator</span><span class="o">*</span> <span class="n">mod</span><span class="p">;</span></div><div class='line' id='LC459'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">channel</span><span class="p">;</span></div><div class='line' id='LC460'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC461'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ModulatorInput</span><span class="p">(</span><span class="n">StereoModulator</span><span class="o">*</span> <span class="n">mod</span><span class="p">,</span> <span class="kt">int</span> <span class="n">channel</span><span class="p">)</span><span class="o">:</span> </div><div class='line' id='LC462'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">mod</span><span class="p">(</span><span class="n">mod</span><span class="p">),</span></div><div class='line' id='LC463'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">channel</span><span class="p">(</span><span class="n">channel</span><span class="p">)</span> <span class="p">{</span> <span class="p">}</span></div><div class='line' id='LC464'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC465'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">void</span> <span class="n">consume</span><span class="p">(</span><span class="kt">float</span><span class="o">*</span> <span class="n">data</span><span class="p">,</span> <span class="kt">int</span> <span class="n">num</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC466'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">mod</span><span class="o">-&gt;</span><span class="n">consume</span><span class="p">(</span><span class="n">data</span><span class="p">,</span> <span class="n">num</span><span class="p">,</span> <span class="n">channel</span><span class="p">);</span></div><div class='line' id='LC467'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC468'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">};</span></div><div class='line' id='LC469'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC470'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">buffer</span><span class="p">[</span><span class="mi">1024</span><span class="p">];</span></div><div class='line' id='LC471'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">bufferOwner</span><span class="p">;</span></div><div class='line' id='LC472'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">bufferLen</span><span class="p">;</span></div><div class='line' id='LC473'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">state</span><span class="p">;</span> <span class="c1">// 8 state state machine.</span></div><div class='line' id='LC474'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">sinLut</span><span class="p">[</span><span class="mi">16</span><span class="p">];</span></div><div class='line' id='LC475'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC476'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">SampleSink</span><span class="o">*</span> <span class="n">next</span><span class="p">;</span></div><div class='line' id='LC477'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC478'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">StereoModulator</span><span class="p">(</span><span class="n">SampleSink</span><span class="o">*</span> <span class="n">next</span><span class="p">)</span><span class="o">:</span> </div><div class='line' id='LC479'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">next</span><span class="p">(</span><span class="n">next</span><span class="p">),</span> <span class="n">bufferOwner</span><span class="p">(</span><span class="mi">0</span><span class="p">),</span> <span class="n">bufferLen</span><span class="p">(</span><span class="mi">0</span><span class="p">),</span> <span class="n">state</span><span class="p">(</span><span class="mi">0</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC480'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span><span class="o">&lt;</span><span class="mi">16</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC481'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">sinLut</span><span class="p">[</span><span class="n">i</span><span class="p">]</span> <span class="o">=</span> <span class="n">sin</span><span class="p">((</span><span class="kt">float</span><span class="p">)</span><span class="n">i</span><span class="o">*</span><span class="mf">2.0</span><span class="o">*</span><span class="n">PI</span><span class="o">/</span><span class="mi">8</span><span class="p">);</span></div><div class='line' id='LC482'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC483'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC484'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC485'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">SampleSink</span><span class="o">*</span> <span class="n">getChannel</span><span class="p">(</span><span class="kt">int</span> <span class="n">channel</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC486'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">return</span> <span class="n">new</span> <span class="n">ModulatorInput</span><span class="p">(</span><span class="n">this</span><span class="p">,</span> <span class="n">channel</span><span class="p">);</span>  <span class="c1">// never freed, cos I&#39;m a rebel...</span></div><div class='line' id='LC487'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span>    </div><div class='line' id='LC488'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC489'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">void</span> <span class="n">consume</span><span class="p">(</span><span class="kt">float</span><span class="o">*</span> <span class="n">data</span><span class="p">,</span> <span class="kt">int</span> <span class="n">num</span><span class="p">,</span> <span class="kt">int</span> <span class="n">channel</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC490'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">channel</span><span class="o">==</span><span class="n">bufferOwner</span> <span class="o">||</span> <span class="n">bufferLen</span><span class="o">==</span><span class="mi">0</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC491'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">bufferOwner</span><span class="o">=</span><span class="n">channel</span><span class="p">;</span></div><div class='line' id='LC492'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// append to buffer</span></div><div class='line' id='LC493'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">while</span><span class="p">(</span><span class="n">num</span> <span class="o">&amp;&amp;</span> <span class="n">bufferLen</span><span class="o">&lt;</span><span class="mi">1024</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC494'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">buffer</span><span class="p">[</span><span class="n">bufferLen</span><span class="o">++</span><span class="p">]</span> <span class="o">=</span> <span class="n">data</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span></div><div class='line' id='LC495'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">data</span><span class="o">++</span><span class="p">;</span></div><div class='line' id='LC496'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">num</span><span class="o">--</span><span class="p">;</span></div><div class='line' id='LC497'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC498'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC499'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">consumable</span> <span class="o">=</span> <span class="p">(</span><span class="n">bufferLen</span><span class="o">&lt;</span><span class="n">num</span><span class="p">)</span><span class="o">?</span><span class="n">bufferLen</span><span class="o">:</span><span class="n">num</span><span class="p">;</span></div><div class='line' id='LC500'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span><span class="o">*</span> <span class="n">left</span> <span class="o">=</span> <span class="p">(</span><span class="n">bufferOwner</span><span class="o">==</span><span class="mi">0</span><span class="p">)</span><span class="o">?</span><span class="n">buffer</span><span class="o">:</span><span class="n">data</span><span class="p">;</span></div><div class='line' id='LC501'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span><span class="o">*</span> <span class="n">right</span> <span class="o">=</span> <span class="p">(</span><span class="n">bufferOwner</span><span class="o">==</span><span class="mi">1</span><span class="p">)</span><span class="o">?</span><span class="n">buffer</span><span class="o">:</span><span class="n">data</span><span class="p">;</span></div><div class='line' id='LC502'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span><span class="o">&lt;</span><span class="n">consumable</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC503'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">state</span> <span class="o">=</span> <span class="p">(</span><span class="n">state</span><span class="o">+</span><span class="mi">1</span><span class="p">)</span> <span class="o">%</span><span class="mi">8</span><span class="p">;</span></div><div class='line' id='LC504'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// equation straight from wikipedia...</span></div><div class='line' id='LC505'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">buffer</span><span class="p">[</span><span class="n">i</span><span class="p">]</span> <span class="o">=</span> <span class="p">((</span><span class="n">left</span><span class="p">[</span><span class="n">i</span><span class="p">]</span><span class="o">+</span><span class="n">right</span><span class="p">[</span><span class="n">i</span><span class="p">])</span><span class="o">/</span><span class="mi">2</span> <span class="o">+</span> <span class="p">(</span><span class="n">left</span><span class="p">[</span><span class="n">i</span><span class="p">]</span><span class="o">-</span><span class="n">right</span><span class="p">[</span><span class="n">i</span><span class="p">])</span><span class="o">/</span><span class="mi">2</span><span class="o">*</span><span class="n">sinLut</span><span class="p">[</span><span class="n">state</span><span class="o">*</span><span class="mi">2</span><span class="p">])</span><span class="o">*</span><span class="mf">0.83</span> <span class="o">+</span> <span class="mf">0.17</span><span class="o">*</span><span class="n">sinLut</span><span class="p">[</span><span class="n">state</span><span class="p">];</span> </div><div class='line' id='LC506'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC507'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">next</span><span class="o">-&gt;</span><span class="n">consume</span><span class="p">(</span><span class="n">buffer</span><span class="p">,</span> <span class="n">consumable</span><span class="p">);</span></div><div class='line' id='LC508'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC509'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// move stuff along buffer</span></div><div class='line' id='LC510'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="n">consumable</span><span class="p">;</span> <span class="n">i</span><span class="o">&lt;</span><span class="n">bufferLen</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC511'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">buffer</span><span class="p">[</span><span class="n">i</span><span class="o">-</span><span class="n">consumable</span><span class="p">]</span> <span class="o">=</span> <span class="n">buffer</span><span class="p">[</span><span class="n">i</span><span class="p">];</span></div><div class='line' id='LC512'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC513'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">bufferLen</span><span class="o">-=</span><span class="n">consumable</span><span class="p">;</span></div><div class='line' id='LC514'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC515'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//reconsume any remaining data</span></div><div class='line' id='LC516'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">data</span> <span class="o">+=</span> <span class="n">consumable</span><span class="p">;</span></div><div class='line' id='LC517'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">num</span> <span class="o">-=</span> <span class="n">consumable</span><span class="p">;</span></div><div class='line' id='LC518'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">consume</span><span class="p">(</span><span class="n">data</span><span class="p">,</span> <span class="n">num</span><span class="p">,</span> <span class="n">channel</span><span class="p">);</span></div><div class='line' id='LC519'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC520'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC521'><span class="p">};</span></div><div class='line' id='LC522'><br/></div><div class='line' id='LC523'><br/></div><div class='line' id='LC524'><span class="kt">void</span> <span class="nf">playWav</span><span class="p">(</span><span class="kt">char</span><span class="o">*</span> <span class="n">filename</span><span class="p">,</span> <span class="kt">float</span> <span class="n">samplerate</span><span class="p">,</span> <span class="kt">bool</span> <span class="n">stereo</span><span class="p">)</span></div><div class='line' id='LC525'><span class="p">{</span></div><div class='line' id='LC526'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">fp</span><span class="o">=</span> <span class="n">STDIN_FILENO</span><span class="p">;</span></div><div class='line' id='LC527'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span><span class="p">(</span><span class="n">filename</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span><span class="o">!=</span><span class="sc">&#39;-&#39;</span><span class="p">)</span> <span class="n">fp</span> <span class="o">=</span> <span class="n">open</span><span class="p">(</span><span class="n">filename</span><span class="p">,</span> <span class="sc">&#39;r&#39;</span><span class="p">);</span></div><div class='line' id='LC528'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC529'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">char</span> <span class="n">data</span><span class="p">[</span><span class="mi">1024</span><span class="p">];</span></div><div class='line' id='LC530'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC531'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">SampleSink</span><span class="o">*</span> <span class="n">ss</span><span class="p">;</span></div><div class='line' id='LC532'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC533'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">stereo</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC534'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">StereoModulator</span><span class="o">*</span> <span class="n">sm</span> <span class="o">=</span> <span class="n">new</span> <span class="n">StereoModulator</span><span class="p">(</span><span class="n">new</span> <span class="n">RDSEncoder</span><span class="p">(</span><span class="n">new</span> <span class="n">Outputter</span><span class="p">(</span><span class="mi">152000</span><span class="p">)));</span></div><div class='line' id='LC535'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ss</span> <span class="o">=</span> <span class="n">new</span> <span class="n">StereoSplitter</span><span class="p">(</span> </div><div class='line' id='LC536'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// left</span></div><div class='line' id='LC537'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">new</span> <span class="n">PreEmp</span><span class="p">(</span><span class="n">samplerate</span><span class="p">,</span> <span class="n">new</span> <span class="n">Resamp</span><span class="p">(</span><span class="n">samplerate</span><span class="p">,</span> <span class="mi">152000</span><span class="p">,</span> <span class="n">sm</span><span class="o">-&gt;</span><span class="n">getChannel</span><span class="p">(</span><span class="mi">0</span><span class="p">))),</span> </div><div class='line' id='LC538'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC539'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// Right</span></div><div class='line' id='LC540'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">new</span> <span class="n">PreEmp</span><span class="p">(</span><span class="n">samplerate</span><span class="p">,</span> <span class="n">new</span> <span class="n">Resamp</span><span class="p">(</span><span class="n">samplerate</span><span class="p">,</span> <span class="mi">152000</span><span class="p">,</span> <span class="n">sm</span><span class="o">-&gt;</span><span class="n">getChannel</span><span class="p">(</span><span class="mi">1</span><span class="p">)))</span></div><div class='line' id='LC541'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">);</span></div><div class='line' id='LC542'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC543'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ss</span> <span class="o">=</span> <span class="n">new</span> <span class="n">Mono</span><span class="p">(</span><span class="n">new</span> <span class="n">PreEmp</span><span class="p">(</span><span class="n">samplerate</span><span class="p">,</span> <span class="n">new</span> <span class="n">Outputter</span><span class="p">(</span><span class="n">samplerate</span><span class="p">)));</span></div><div class='line' id='LC544'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC545'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC546'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span><span class="o">&lt;</span><span class="mi">22</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span></div><div class='line' id='LC547'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">read</span><span class="p">(</span><span class="n">fp</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">data</span><span class="p">,</span> <span class="mi">2</span><span class="p">);</span>  <span class="c1">// read past header</span></div><div class='line' id='LC548'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC549'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">readBytes</span><span class="p">;</span></div><div class='line' id='LC550'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">while</span> <span class="p">(</span><span class="n">readBytes</span> <span class="o">=</span> <span class="n">read</span><span class="p">(</span><span class="n">fp</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">data</span><span class="p">,</span> <span class="mi">1024</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC551'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC552'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ss</span><span class="o">-&gt;</span><span class="n">consume</span><span class="p">(</span><span class="n">data</span><span class="p">,</span> <span class="n">readBytes</span><span class="p">);</span></div><div class='line' id='LC553'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC554'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">close</span><span class="p">(</span><span class="n">fp</span><span class="p">);</span></div><div class='line' id='LC555'><span class="p">}</span></div><div class='line' id='LC556'><br/></div><div class='line' id='LC557'><span class="kt">void</span> <span class="nf">unSetupDMA</span><span class="p">(){</span></div><div class='line' id='LC558'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">printf</span><span class="p">(</span><span class="s">&quot;exiting</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">);</span></div><div class='line' id='LC559'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">struct</span> <span class="n">DMAregs</span><span class="o">*</span> <span class="n">DMA0</span> <span class="o">=</span> <span class="p">(</span><span class="k">struct</span> <span class="n">DMAregs</span><span class="o">*</span><span class="p">)</span><span class="o">&amp;</span><span class="p">(</span><span class="n">ACCESS</span><span class="p">(</span><span class="n">DMABASE</span><span class="p">));</span></div><div class='line' id='LC560'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">DMA0</span><span class="o">-&gt;</span><span class="n">CS</span> <span class="o">=</span><span class="mi">1</span><span class="o">&lt;&lt;</span><span class="mi">31</span><span class="p">;</span>  <span class="c1">// reset dma controller</span></div><div class='line' id='LC561'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC562'><span class="p">}</span></div><div class='line' id='LC563'><br/></div><div class='line' id='LC564'><span class="kt">void</span> <span class="nf">handSig</span><span class="p">(</span><span class="kt">int</span> <span class="n">dunno</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC565'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">exit</span><span class="p">(</span><span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC566'><span class="p">}</span></div><div class='line' id='LC567'><span class="kt">void</span> <span class="nf">setupDMA</span><span class="p">(</span> <span class="kt">float</span> <span class="n">centerFreq</span> <span class="p">){</span></div><div class='line' id='LC568'><br/></div><div class='line' id='LC569'>&nbsp;&nbsp;<span class="n">atexit</span><span class="p">(</span><span class="n">unSetupDMA</span><span class="p">);</span></div><div class='line' id='LC570'>&nbsp;&nbsp;<span class="n">signal</span> <span class="p">(</span><span class="n">SIGINT</span><span class="p">,</span> <span class="n">handSig</span><span class="p">);</span></div><div class='line' id='LC571'>&nbsp;&nbsp;<span class="n">signal</span> <span class="p">(</span><span class="n">SIGTERM</span><span class="p">,</span> <span class="n">handSig</span><span class="p">);</span></div><div class='line' id='LC572'>&nbsp;&nbsp;<span class="n">signal</span> <span class="p">(</span><span class="n">SIGHUP</span><span class="p">,</span> <span class="n">handSig</span><span class="p">);</span></div><div class='line' id='LC573'>&nbsp;&nbsp;<span class="n">signal</span> <span class="p">(</span><span class="n">SIGQUIT</span><span class="p">,</span> <span class="n">handSig</span><span class="p">);</span></div><div class='line' id='LC574'><br/></div><div class='line' id='LC575'>&nbsp;&nbsp;&nbsp;<span class="c1">// allocate a few pages of ram</span></div><div class='line' id='LC576'>&nbsp;&nbsp;&nbsp;<span class="n">getRealMemPage</span><span class="p">(</span><span class="o">&amp;</span><span class="n">constPage</span><span class="p">.</span><span class="n">v</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">constPage</span><span class="p">.</span><span class="n">p</span><span class="p">);</span></div><div class='line' id='LC577'>&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC578'>&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">centerFreqDivider</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)((</span><span class="mf">500.0</span> <span class="o">/</span> <span class="n">centerFreq</span><span class="p">)</span> <span class="o">*</span> <span class="p">(</span><span class="kt">float</span><span class="p">)(</span><span class="mi">1</span><span class="o">&lt;&lt;</span><span class="mi">12</span><span class="p">)</span> <span class="o">+</span> <span class="mf">0.5</span><span class="p">);</span></div><div class='line' id='LC579'>&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC580'>&nbsp;&nbsp;&nbsp;<span class="c1">// make data page contents - it&#39;s essientially 1024 different commands for the</span></div><div class='line' id='LC581'>&nbsp;&nbsp;&nbsp;<span class="c1">// DMA controller to send to the clock module at the correct time.</span></div><div class='line' id='LC582'>&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span><span class="o">&lt;</span><span class="mi">1024</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span></div><div class='line' id='LC583'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">((</span><span class="kt">int</span><span class="o">*</span><span class="p">)(</span><span class="n">constPage</span><span class="p">.</span><span class="n">v</span><span class="p">))[</span><span class="n">i</span><span class="p">]</span> <span class="o">=</span> <span class="p">(</span><span class="mh">0x5a</span> <span class="o">&lt;&lt;</span> <span class="mi">24</span><span class="p">)</span> <span class="o">+</span> <span class="n">centerFreqDivider</span> <span class="o">-</span> <span class="mi">512</span> <span class="o">+</span> <span class="n">i</span><span class="p">;</span></div><div class='line' id='LC584'>&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC585'>&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC586'>&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">instrCnt</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC587'>&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC588'>&nbsp;&nbsp;&nbsp;<span class="k">while</span> <span class="p">(</span><span class="n">instrCnt</span><span class="o">&lt;</span><span class="n">BUFFERINSTRUCTIONS</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC589'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">getRealMemPage</span><span class="p">(</span><span class="o">&amp;</span><span class="n">instrPage</span><span class="p">.</span><span class="n">v</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">instrPage</span><span class="p">.</span><span class="n">p</span><span class="p">);</span></div><div class='line' id='LC590'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC591'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// make copy instructions</span></div><div class='line' id='LC592'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">struct</span> <span class="n">CB</span><span class="o">*</span> <span class="n">instr0</span><span class="o">=</span> <span class="p">(</span><span class="k">struct</span> <span class="n">CB</span><span class="o">*</span><span class="p">)</span><span class="n">instrPage</span><span class="p">.</span><span class="n">v</span><span class="p">;</span></div><div class='line' id='LC593'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC594'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span><span class="o">&lt;</span><span class="mi">4096</span><span class="o">/</span><span class="k">sizeof</span><span class="p">(</span><span class="k">struct</span> <span class="n">CB</span><span class="p">);</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC595'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">instrs</span><span class="p">[</span><span class="n">instrCnt</span><span class="p">].</span><span class="n">v</span> <span class="o">=</span> <span class="p">(</span><span class="kt">void</span><span class="o">*</span><span class="p">)((</span><span class="kt">int</span><span class="p">)</span><span class="n">instrPage</span><span class="p">.</span><span class="n">v</span> <span class="o">+</span> <span class="k">sizeof</span><span class="p">(</span><span class="k">struct</span> <span class="n">CB</span><span class="p">)</span><span class="o">*</span><span class="n">i</span><span class="p">);</span></div><div class='line' id='LC596'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">instrs</span><span class="p">[</span><span class="n">instrCnt</span><span class="p">].</span><span class="n">p</span> <span class="o">=</span> <span class="p">(</span><span class="kt">void</span><span class="o">*</span><span class="p">)((</span><span class="kt">int</span><span class="p">)</span><span class="n">instrPage</span><span class="p">.</span><span class="n">p</span> <span class="o">+</span> <span class="k">sizeof</span><span class="p">(</span><span class="k">struct</span> <span class="n">CB</span><span class="p">)</span><span class="o">*</span><span class="n">i</span><span class="p">);</span></div><div class='line' id='LC597'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">instr0</span><span class="o">-&gt;</span><span class="n">SOURCE_AD</span> <span class="o">=</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">constPage</span><span class="p">.</span><span class="n">p</span><span class="o">+</span><span class="mi">2048</span><span class="p">;</span></div><div class='line' id='LC598'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">instr0</span><span class="o">-&gt;</span><span class="n">DEST_AD</span> <span class="o">=</span> <span class="n">PWMBASE</span><span class="o">+</span><span class="mh">0x18</span> <span class="cm">/* FIF1 */</span><span class="p">;</span></div><div class='line' id='LC599'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">instr0</span><span class="o">-&gt;</span><span class="n">TXFR_LEN</span> <span class="o">=</span> <span class="mi">4</span><span class="p">;</span></div><div class='line' id='LC600'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">instr0</span><span class="o">-&gt;</span><span class="n">STRIDE</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC601'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//instr0-&gt;NEXTCONBK = (int)instrPage.p + sizeof(struct CB)*(i+1);</span></div><div class='line' id='LC602'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">instr0</span><span class="o">-&gt;</span><span class="n">TI</span> <span class="o">=</span> <span class="p">(</span><span class="mi">1</span><span class="cm">/* DREQ  */</span><span class="o">&lt;&lt;</span><span class="mi">6</span><span class="p">)</span> <span class="o">|</span> <span class="p">(</span><span class="mi">5</span> <span class="cm">/* PWM */</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">)</span> <span class="o">|</span>  <span class="p">(</span><span class="mi">1</span><span class="o">&lt;&lt;</span><span class="mi">26</span><span class="cm">/* no wide*/</span><span class="p">)</span> <span class="p">;</span></div><div class='line' id='LC603'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">instr0</span><span class="o">-&gt;</span><span class="n">RES1</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC604'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">instr0</span><span class="o">-&gt;</span><span class="n">RES2</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC605'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC606'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="p">(</span><span class="n">i</span><span class="o">%</span><span class="mi">2</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC607'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">instr0</span><span class="o">-&gt;</span><span class="n">DEST_AD</span> <span class="o">=</span> <span class="n">CM_GP0DIV</span><span class="p">;</span></div><div class='line' id='LC608'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">instr0</span><span class="o">-&gt;</span><span class="n">STRIDE</span> <span class="o">=</span> <span class="mi">4</span><span class="p">;</span></div><div class='line' id='LC609'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">instr0</span><span class="o">-&gt;</span><span class="n">TI</span> <span class="o">=</span> <span class="p">(</span><span class="mi">1</span><span class="o">&lt;&lt;</span><span class="mi">26</span><span class="cm">/* no wide*/</span><span class="p">)</span> <span class="p">;</span></div><div class='line' id='LC610'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC611'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC612'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">instrCnt</span><span class="o">!=</span><span class="mi">0</span><span class="p">)</span> <span class="p">((</span><span class="k">struct</span> <span class="n">CB</span><span class="o">*</span><span class="p">)(</span><span class="n">instrs</span><span class="p">[</span><span class="n">instrCnt</span><span class="o">-</span><span class="mi">1</span><span class="p">].</span><span class="n">v</span><span class="p">))</span><span class="o">-&gt;</span><span class="n">NEXTCONBK</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">instrs</span><span class="p">[</span><span class="n">instrCnt</span><span class="p">].</span><span class="n">p</span><span class="p">;</span></div><div class='line' id='LC613'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">instr0</span><span class="o">++</span><span class="p">;</span></div><div class='line' id='LC614'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">instrCnt</span><span class="o">++</span><span class="p">;</span></div><div class='line' id='LC615'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC616'>&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC617'>&nbsp;&nbsp;&nbsp;<span class="p">((</span><span class="k">struct</span> <span class="n">CB</span><span class="o">*</span><span class="p">)(</span><span class="n">instrs</span><span class="p">[</span><span class="n">BUFFERINSTRUCTIONS</span><span class="o">-</span><span class="mi">1</span><span class="p">].</span><span class="n">v</span><span class="p">))</span><span class="o">-&gt;</span><span class="n">NEXTCONBK</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">instrs</span><span class="p">[</span><span class="mi">0</span><span class="p">].</span><span class="n">p</span><span class="p">;</span></div><div class='line' id='LC618'>&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC619'>&nbsp;&nbsp;&nbsp;<span class="c1">// set up a clock for the PWM</span></div><div class='line' id='LC620'>&nbsp;&nbsp;&nbsp;<span class="n">ACCESS</span><span class="p">(</span><span class="n">CLKBASE</span> <span class="o">+</span> <span class="mi">40</span><span class="o">*</span><span class="mi">4</span> <span class="cm">/*PWMCLK_CNTL*/</span><span class="p">)</span> <span class="o">=</span> <span class="mh">0x5A000026</span><span class="p">;</span></div><div class='line' id='LC621'>&nbsp;&nbsp;&nbsp;<span class="n">usleep</span><span class="p">(</span><span class="mi">1000</span><span class="p">);</span></div><div class='line' id='LC622'>&nbsp;&nbsp;&nbsp;<span class="n">ACCESS</span><span class="p">(</span><span class="n">CLKBASE</span> <span class="o">+</span> <span class="mi">41</span><span class="o">*</span><span class="mi">4</span> <span class="cm">/*PWMCLK_DIV*/</span><span class="p">)</span>  <span class="o">=</span> <span class="mh">0x5A002800</span><span class="p">;</span></div><div class='line' id='LC623'>&nbsp;&nbsp;&nbsp;<span class="n">ACCESS</span><span class="p">(</span><span class="n">CLKBASE</span> <span class="o">+</span> <span class="mi">40</span><span class="o">*</span><span class="mi">4</span> <span class="cm">/*PWMCLK_CNTL*/</span><span class="p">)</span> <span class="o">=</span> <span class="mh">0x5A000016</span><span class="p">;</span></div><div class='line' id='LC624'>&nbsp;&nbsp;&nbsp;<span class="n">usleep</span><span class="p">(</span><span class="mi">1000</span><span class="p">);</span> </div><div class='line' id='LC625'><br/></div><div class='line' id='LC626'>&nbsp;&nbsp;&nbsp;<span class="c1">// set up pwm</span></div><div class='line' id='LC627'>&nbsp;&nbsp;&nbsp;<span class="n">ACCESS</span><span class="p">(</span><span class="n">PWMBASE</span> <span class="o">+</span> <span class="mh">0x0</span> <span class="cm">/* CTRL*/</span><span class="p">)</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC628'>&nbsp;&nbsp;&nbsp;<span class="n">usleep</span><span class="p">(</span><span class="mi">1000</span><span class="p">);</span></div><div class='line' id='LC629'>&nbsp;&nbsp;&nbsp;<span class="n">ACCESS</span><span class="p">(</span><span class="n">PWMBASE</span> <span class="o">+</span> <span class="mh">0x4</span> <span class="cm">/* status*/</span><span class="p">)</span> <span class="o">=</span> <span class="o">-</span><span class="mi">1</span><span class="p">;</span>  <span class="c1">// clear errors</span></div><div class='line' id='LC630'>&nbsp;&nbsp;&nbsp;<span class="n">usleep</span><span class="p">(</span><span class="mi">1000</span><span class="p">);</span></div><div class='line' id='LC631'>&nbsp;&nbsp;&nbsp;<span class="n">ACCESS</span><span class="p">(</span><span class="n">PWMBASE</span> <span class="o">+</span> <span class="mh">0x0</span> <span class="cm">/* CTRL*/</span><span class="p">)</span> <span class="o">=</span> <span class="o">-</span><span class="mi">1</span><span class="p">;</span> <span class="c1">//(1&lt;&lt;13 /* Use fifo */) | (1&lt;&lt;10 /* repeat */) | (1&lt;&lt;9 /* serializer */) | (1&lt;&lt;8 /* enable ch */) ;</span></div><div class='line' id='LC632'>&nbsp;&nbsp;&nbsp;<span class="n">usleep</span><span class="p">(</span><span class="mi">1000</span><span class="p">);</span></div><div class='line' id='LC633'>&nbsp;&nbsp;&nbsp;<span class="n">ACCESS</span><span class="p">(</span><span class="n">PWMBASE</span> <span class="o">+</span> <span class="mh">0x8</span> <span class="cm">/* DMAC*/</span><span class="p">)</span> <span class="o">=</span> <span class="p">(</span><span class="mi">1</span><span class="o">&lt;&lt;</span><span class="mi">31</span> <span class="cm">/* DMA enable */</span><span class="p">)</span> <span class="o">|</span> <span class="mh">0x0707</span><span class="p">;</span></div><div class='line' id='LC634'>&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC635'>&nbsp;&nbsp;&nbsp;<span class="c1">//activate dma</span></div><div class='line' id='LC636'>&nbsp;&nbsp;&nbsp;<span class="k">struct</span> <span class="n">DMAregs</span><span class="o">*</span> <span class="n">DMA0</span> <span class="o">=</span> <span class="p">(</span><span class="k">struct</span> <span class="n">DMAregs</span><span class="o">*</span><span class="p">)</span><span class="o">&amp;</span><span class="p">(</span><span class="n">ACCESS</span><span class="p">(</span><span class="n">DMABASE</span><span class="p">));</span></div><div class='line' id='LC637'>&nbsp;&nbsp;&nbsp;<span class="n">DMA0</span><span class="o">-&gt;</span><span class="n">CS</span> <span class="o">=</span><span class="mi">1</span><span class="o">&lt;&lt;</span><span class="mi">31</span><span class="p">;</span>  <span class="c1">// reset</span></div><div class='line' id='LC638'>&nbsp;&nbsp;&nbsp;<span class="n">DMA0</span><span class="o">-&gt;</span><span class="n">CONBLK_AD</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> </div><div class='line' id='LC639'>&nbsp;&nbsp;&nbsp;<span class="n">DMA0</span><span class="o">-&gt;</span><span class="n">TI</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> </div><div class='line' id='LC640'>&nbsp;&nbsp;&nbsp;<span class="n">DMA0</span><span class="o">-&gt;</span><span class="n">CONBLK_AD</span> <span class="o">=</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)(</span><span class="n">instrPage</span><span class="p">.</span><span class="n">p</span><span class="p">);</span></div><div class='line' id='LC641'>&nbsp;&nbsp;&nbsp;<span class="n">DMA0</span><span class="o">-&gt;</span><span class="n">CS</span> <span class="o">=</span><span class="p">(</span><span class="mi">1</span><span class="o">&lt;&lt;</span><span class="mi">0</span><span class="p">)</span><span class="o">|</span><span class="p">(</span><span class="mi">255</span> <span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">);</span>  <span class="c1">// enable bit = 0, clear end flag = 1, prio=19-16</span></div><div class='line' id='LC642'><span class="p">}</span></div><div class='line' id='LC643'><br/></div><div class='line' id='LC644'><br/></div><div class='line' id='LC645'><br/></div><div class='line' id='LC646'><span class="kt">int</span> <span class="nf">main</span><span class="p">(</span><span class="kt">int</span> <span class="n">argc</span><span class="p">,</span> <span class="kt">char</span> <span class="o">**</span><span class="n">argv</span><span class="p">)</span></div><div class='line' id='LC647'><span class="p">{</span></div><div class='line' id='LC648'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC649'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">argc</span><span class="o">&gt;</span><span class="mi">1</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC650'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">setup_fm</span><span class="p">();</span></div><div class='line' id='LC651'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">setupDMA</span><span class="p">(</span><span class="n">argc</span><span class="o">&gt;</span><span class="mi">2</span><span class="o">?</span><span class="n">atof</span><span class="p">(</span><span class="n">argv</span><span class="p">[</span><span class="mi">2</span><span class="p">])</span><span class="o">:</span><span class="mf">103.3</span><span class="p">);</span></div><div class='line' id='LC652'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">playWav</span><span class="p">(</span><span class="n">argv</span><span class="p">[</span><span class="mi">1</span><span class="p">],</span> <span class="n">argc</span><span class="o">&gt;</span><span class="mi">3</span><span class="o">?</span><span class="n">atof</span><span class="p">(</span><span class="n">argv</span><span class="p">[</span><span class="mi">3</span><span class="p">])</span><span class="o">:</span><span class="mi">22050</span><span class="p">,</span> <span class="n">argc</span><span class="o">&gt;</span><span class="mi">4</span><span class="p">);</span></div><div class='line' id='LC653'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span></div><div class='line' id='LC654'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">fprintf</span><span class="p">(</span><span class="n">stderr</span><span class="p">,</span> <span class="s">&quot;Usage:   program wavfile.wav [freq] [sample rate] [stereo]</span><span class="se">\n\n</span><span class="s">Where wavfile is 16 bit 22.5kHz Stereo.  Set wavfile to &#39;-&#39; to use stdin.</span><span class="se">\n</span><span class="s">freq is in Mhz (default 103.3)</span><span class="se">\n</span><span class="s">sample rate of wav file in Hz</span><span class="se">\n\n</span><span class="s">Play an empty file to transmit silence</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">);</span></div><div class='line' id='LC655'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC656'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">return</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC657'><br/></div><div class='line' id='LC658'><span class="p">}</span> <span class="c1">// main</span></div><div class='line' id='LC659'><br/></div></pre></div></td>
          </tr>
        </table>
  </div>

  </div>
</div>

<a href="#jump-to-line" rel="facebox[.linejump]" data-hotkey="l" class="js-jump-to-line" style="display:none">Jump to Line</a>
<div id="jump-to-line" style="display:none">
  <form accept-charset="UTF-8" class="js-jump-to-line-form">
    <input class="linejump-input js-jump-to-line-field" type="text" placeholder="Jump to line&hellip;" autofocus>
    <button type="submit" class="button">Go</button>
  </form>
</div>

        </div>

      </div><!-- /.repo-container -->
      <div class="modal-backdrop"></div>
    </div><!-- /.container -->
  </div><!-- /.site -->


    </div><!-- /.wrapper -->

      <div class="container">
  <div class="site-footer">
    <ul class="site-footer-links right">
      <li><a href="https://status.github.com/">Status</a></li>
      <li><a href="http://developer.github.com">API</a></li>
      <li><a href="http://training.github.com">Training</a></li>
      <li><a href="http://shop.github.com">Shop</a></li>
      <li><a href="/blog">Blog</a></li>
      <li><a href="/about">About</a></li>

    </ul>

    <a href="/">
      <span class="mega-octicon octicon-mark-github" title="GitHub"></span>
    </a>

    <ul class="site-footer-links">
      <li>&copy; 2014 <span title="0.06953s from github-fe134-cp1-prd.iad.github.net">GitHub</span>, Inc.</li>
        <li><a href="/site/terms">Terms</a></li>
        <li><a href="/site/privacy">Privacy</a></li>
        <li><a href="/security">Security</a></li>
        <li><a href="/contact">Contact</a></li>
    </ul>
  </div><!-- /.site-footer -->
</div><!-- /.container -->


    <div class="fullscreen-overlay js-fullscreen-overlay" id="fullscreen_overlay">
  <div class="fullscreen-container js-fullscreen-container">
    <div class="textarea-wrap">
      <textarea name="fullscreen-contents" id="fullscreen-contents" class="fullscreen-contents js-fullscreen-contents" placeholder="" data-suggester="fullscreen_suggester"></textarea>
    </div>
  </div>
  <div class="fullscreen-sidebar">
    <a href="#" class="exit-fullscreen js-exit-fullscreen tooltipped tooltipped-w" aria-label="Exit Zen Mode">
      <span class="mega-octicon octicon-screen-normal"></span>
    </a>
    <a href="#" class="theme-switcher js-theme-switcher tooltipped tooltipped-w"
      aria-label="Switch themes">
      <span class="octicon octicon-color-mode"></span>
    </a>
  </div>
</div>



    <div id="ajax-error-message" class="flash flash-error">
      <span class="octicon octicon-alert"></span>
      <a href="#" class="octicon octicon-remove-close close js-ajax-error-dismiss"></a>
      Something went wrong with that request. Please try again.
    </div>

  </body>
</html>

