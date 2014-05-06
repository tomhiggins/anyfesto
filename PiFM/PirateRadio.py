




<!DOCTYPE html>
<html class="   ">
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# object: http://ogp.me/ns/object# article: http://ogp.me/ns/article# profile: http://ogp.me/ns/profile#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    
    
    <title>PirateRadio/PirateRadio.py at master · Make-Magazine/PirateRadio</title>
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
    <meta content="collector.githubapp.com" name="octolytics-host" /><meta content="collector-cdn.github.com" name="octolytics-script-host" /><meta content="github" name="octolytics-app-id" /><meta content="18087386:1FFF:6B9BAC1:536842B7" name="octolytics-dimension-request_id" /><meta content="56514" name="octolytics-actor-id" /><meta content="tomhiggins" name="octolytics-actor-login" /><meta content="39298c5b45166ae116d8c0be337d820bc8c507000f78f4c59d424239d8bae232" name="octolytics-actor-hash" />
    

    
    
    <link rel="icon" type="image/x-icon" href="https://github.global.ssl.fastly.net/favicon.ico" />

    <meta content="authenticity_token" name="csrf-param" />
<meta content="bBoyE8Gr4kwVZzQGr51B8ngBEvzswxN5emTE7QF6UmtV7u+vabsyRQSJqJVRNW3/U/1eKkz/ruOY9Gez9MKrdw==" name="csrf-token" />

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
      <form accept-charset="UTF-8" action="/notifications/subscribe" class="js-social-container" data-autosubmit="true" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="QhNAhg0PjFPZ7LYJahjTwPSw+hURLmVUzfdnkwKrg7V1FuxQ2ljPASYoXqxOgT2SbR1YfKvo0IXP5e/S8LYn2g==" /></div>  <input id="repository_id" name="repository_id" type="hidden" value="17536738" />

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

    <form accept-charset="UTF-8" action="/Make-Magazine/PirateRadio/unstar" class="js-toggler-form starred" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="bMNob8s8CpTwRWIK+O6Y34orfp2qicmeLz6m0m7rJsf7lcENDr8aKZOA0x/OVkoP6d/CNwbtJOqnm0G402N4qw==" /></div>
      <button
        class="minibutton with-count js-toggler-target star-button"
        aria-label="Unstar this repository" title="Unstar Make-Magazine/PirateRadio">
        <span class="octicon octicon-star-delete"></span><span class="text">Unstar</span>
      </button>
        <a class="social-count js-social-count" href="/Make-Magazine/PirateRadio/stargazers">
          73
        </a>
</form>
    <form accept-charset="UTF-8" action="/Make-Magazine/PirateRadio/star" class="js-toggler-form unstarred" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="1svt4nxolMWsDIfEMZkg44hK3r40vWx8oHTnp6nkpF5W4ScT1aq+6thhXRBaU5jGG9F7AmWTWtaAUdtBumXNQw==" /></div>
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
          

<a href="/Make-Magazine/PirateRadio/blob/093df74e8d1af67fe406460a0b9886cb044096f6/PirateRadio.py" class="hidden js-permalink-shortcut" data-hotkey="y">Permalink</a>

<!-- blob contrib key: blob_contributors:v21:5c79b2a6d2001f9574d4eb5d1a9e947f -->

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
              <a href="/Make-Magazine/PirateRadio/blob/master/PirateRadio.py"
                 data-name="master"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="master">master</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Make-Magazine/PirateRadio/blob/unstable/PirateRadio.py"
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
    <span class='repo-root js-repo-root'><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/Make-Magazine/PirateRadio" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">PirateRadio</span></a></span></span><span class="separator"> / </span><strong class="final-path">PirateRadio.py</strong> <button aria-label="copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="PirateRadio.py" data-copied-hint="copied!" type="button"><span class="octicon octicon-clippy"></span></button>
  </div>
</div>


  <div class="commit file-history-tease">
    <img alt="d4m4s74" class="main-avatar js-avatar" data-user="3111946" height="24" src="https://avatars2.githubusercontent.com/u/3111946?s=140" width="24" />
    <span class="author"><a href="/d4m4s74" rel="author">d4m4s74</a></span>
    <time class="js-relative-date" data-title-format="YYYY-MM-DD HH:mm:ss" datetime="2014-03-08T22:32:23+01:00" title="2014-03-08 16:32:23">March 08, 2014</time>
    <div class="commit-title">
        <a href="/Make-Magazine/PirateRadio/commit/0b676393249d1f46dcfbe9718a08a0fff96d7aee" class="message" data-pjax="true" title="Added Streaming Internet Radio support

Removed all dependencies, ready for merge.">Added Streaming Internet Radio support</a>
    </div>

    <div class="participation">
      <p class="quickstat"><a href="#blob_contributors_box" rel="facebox"><strong>2</strong>  contributors</a></p>
          <a class="avatar tooltipped tooltipped-s" aria-label="zerotri" href="/Make-Magazine/PirateRadio/commits/master/PirateRadio.py?author=zerotri"><img alt="Wynter Woods" class=" js-avatar" data-user="226539" height="20" src="https://avatars0.githubusercontent.com/u/226539?s=140" width="20" /></a>
    <a class="avatar tooltipped tooltipped-s" aria-label="d4m4s74" href="/Make-Magazine/PirateRadio/commits/master/PirateRadio.py?author=d4m4s74"><img alt="d4m4s74" class=" js-avatar" data-user="3111946" height="20" src="https://avatars2.githubusercontent.com/u/3111946?s=140" width="20" /></a>


    </div>
    <div id="blob_contributors_box" style="display:none">
      <h2 class="facebox-header">Users who have contributed to this file</h2>
      <ul class="facebox-user-list">
          <li class="facebox-user-list-item">
            <img alt="Wynter Woods" class=" js-avatar" data-user="226539" height="24" src="https://avatars0.githubusercontent.com/u/226539?s=140" width="24" />
            <a href="/zerotri">zerotri</a>
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
        <span class="mode" title="File Mode">executable file</span>
        <span class="meta-divider"></span>
          <span>174 lines (135 sloc)</span>
          <span class="meta-divider"></span>
        <span>4.496 kb</span>
      </div>
      <div class="actions">
        <div class="button-group">
                <a class="minibutton tooltipped tooltipped-n js-update-url-with-hash"
                   aria-label="Clicking this button will automatically fork this project so you can edit the file"
                   href="/Make-Magazine/PirateRadio/edit/master/PirateRadio.py"
                   data-method="post" rel="nofollow">Edit</a>
          <a href="/Make-Magazine/PirateRadio/raw/master/PirateRadio.py" class="button minibutton " id="raw-url">Raw</a>
            <a href="/Make-Magazine/PirateRadio/blame/master/PirateRadio.py" class="button minibutton js-update-url-with-hash">Blame</a>
          <a href="/Make-Magazine/PirateRadio/commits/master/PirateRadio.py" class="button minibutton " rel="nofollow">History</a>
        </div><!-- /.button-group -->

            <a class="minibutton danger empty-icon tooltipped tooltipped-s"
               href="/Make-Magazine/PirateRadio/delete/master/PirateRadio.py"
               aria-label="Fork this project and delete file"
               data-method="post" data-test-id="delete-blob-file" rel="nofollow">

          Delete
        </a>
      </div><!-- /.actions -->
    </div>
        <div class="blob-wrapper data type-python js-blob-data">
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

            </td>
            <td class="blob-line-code"><div class="code-body highlight"><pre><div class='line' id='LC1'><span class="c">#!/usr/bin/env python</span></div><div class='line' id='LC2'><span class="c"># Pirate Radio</span></div><div class='line' id='LC3'><span class="c"># Author: Wynter Woods (Make Magazine)</span></div><div class='line' id='LC4'><br/></div><div class='line' id='LC5'><span class="kn">import</span> <span class="nn">os</span></div><div class='line' id='LC6'><span class="kn">import</span> <span class="nn">sys</span></div><div class='line' id='LC7'><span class="kn">import</span> <span class="nn">subprocess</span></div><div class='line' id='LC8'><span class="kn">import</span> <span class="nn">configparser</span></div><div class='line' id='LC9'><span class="kn">import</span> <span class="nn">re</span></div><div class='line' id='LC10'><span class="kn">import</span> <span class="nn">random</span></div><div class='line' id='LC11'><span class="kn">import</span> <span class="nn">threading</span></div><div class='line' id='LC12'><span class="kn">import</span> <span class="nn">time</span></div><div class='line' id='LC13'><br/></div><div class='line' id='LC14'><br/></div><div class='line' id='LC15'><span class="n">fm_process</span> <span class="o">=</span> <span class="bp">None</span></div><div class='line' id='LC16'><span class="n">on_off</span> <span class="o">=</span> <span class="p">[</span><span class="s">&quot;off&quot;</span><span class="p">,</span> <span class="s">&quot;on&quot;</span><span class="p">]</span></div><div class='line' id='LC17'><br/></div><div class='line' id='LC18'><span class="n">frequency</span> <span class="o">=</span> <span class="mf">87.9</span></div><div class='line' id='LC19'><span class="n">shuffle</span> <span class="o">=</span> <span class="bp">False</span></div><div class='line' id='LC20'><span class="n">repeat_all</span> <span class="o">=</span> <span class="bp">False</span></div><div class='line' id='LC21'><span class="n">merge_audio_in</span> <span class="o">=</span> <span class="bp">False</span></div><div class='line' id='LC22'><span class="n">play_stereo</span> <span class="o">=</span> <span class="bp">True</span></div><div class='line' id='LC23'><br/></div><div class='line' id='LC24'><span class="n">music_pipe_r</span><span class="p">,</span><span class="n">music_pipe_w</span> <span class="o">=</span> <span class="n">os</span><span class="o">.</span><span class="n">pipe</span><span class="p">()</span></div><div class='line' id='LC25'><span class="n">microphone_pipe_r</span><span class="p">,</span><span class="n">microphone_pipe_w</span> <span class="o">=</span> <span class="n">os</span><span class="o">.</span><span class="n">pipe</span><span class="p">()</span></div><div class='line' id='LC26'><br/></div><div class='line' id='LC27'><span class="k">def</span> <span class="nf">main</span><span class="p">():</span></div><div class='line' id='LC28'>	<span class="n">daemonize</span><span class="p">()</span></div><div class='line' id='LC29'>	<span class="n">setup</span><span class="p">()</span></div><div class='line' id='LC30'>	<span class="n">files</span> <span class="o">=</span> <span class="n">build_file_list</span><span class="p">()</span></div><div class='line' id='LC31'>	<span class="k">if</span> <span class="n">repeat_all</span> <span class="o">==</span> <span class="bp">True</span><span class="p">:</span></div><div class='line' id='LC32'>		<span class="k">while</span><span class="p">(</span><span class="bp">True</span><span class="p">):</span></div><div class='line' id='LC33'>			<span class="n">play_songs</span><span class="p">(</span><span class="n">files</span><span class="p">)</span></div><div class='line' id='LC34'>	<span class="k">else</span><span class="p">:</span></div><div class='line' id='LC35'>		<span class="n">play_songs</span><span class="p">(</span><span class="n">files</span><span class="p">)</span></div><div class='line' id='LC36'>	<span class="k">return</span> <span class="mi">0</span></div><div class='line' id='LC37'><br/></div><div class='line' id='LC38'><br/></div><div class='line' id='LC39'><br/></div><div class='line' id='LC40'><span class="k">def</span> <span class="nf">build_file_list</span><span class="p">():</span></div><div class='line' id='LC41'>	<span class="n">file_list</span> <span class="o">=</span> <span class="p">[]</span></div><div class='line' id='LC42'>	<span class="k">for</span> <span class="n">root</span><span class="p">,</span> <span class="n">folders</span><span class="p">,</span> <span class="n">files</span> <span class="ow">in</span> <span class="n">os</span><span class="o">.</span><span class="n">walk</span><span class="p">(</span><span class="s">&quot;/pirateradio&quot;</span><span class="p">):</span></div><div class='line' id='LC43'>		<span class="n">folders</span><span class="o">.</span><span class="n">sort</span><span class="p">()</span></div><div class='line' id='LC44'>		<span class="n">files</span><span class="o">.</span><span class="n">sort</span><span class="p">()</span></div><div class='line' id='LC45'>		<span class="k">for</span> <span class="n">filename</span> <span class="ow">in</span> <span class="n">files</span><span class="p">:</span></div><div class='line' id='LC46'>			<span class="k">if</span> <span class="n">re</span><span class="o">.</span><span class="n">search</span><span class="p">(</span><span class="s">&quot;.(aac|mp3|wav|flac|m4a|pls|m3u)$&quot;</span><span class="p">,</span> <span class="n">filename</span><span class="p">)</span> <span class="o">!=</span> <span class="bp">None</span><span class="p">:</span> </div><div class='line' id='LC47'>				<span class="n">file_list</span><span class="o">.</span><span class="n">append</span><span class="p">(</span><span class="n">os</span><span class="o">.</span><span class="n">path</span><span class="o">.</span><span class="n">join</span><span class="p">(</span><span class="n">root</span><span class="p">,</span> <span class="n">filename</span><span class="p">))</span></div><div class='line' id='LC48'>	<span class="k">return</span> <span class="n">file_list</span></div><div class='line' id='LC49'><br/></div><div class='line' id='LC50'><br/></div><div class='line' id='LC51'><br/></div><div class='line' id='LC52'><span class="k">def</span> <span class="nf">play_songs</span><span class="p">(</span><span class="n">file_list</span><span class="p">):</span></div><div class='line' id='LC53'>	<span class="k">print</span><span class="p">(</span><span class="s">&quot;Playing songs to frequency &quot;</span><span class="p">,</span> <span class="nb">str</span><span class="p">(</span><span class="n">frequency</span><span class="p">))</span></div><div class='line' id='LC54'>	<span class="k">print</span><span class="p">(</span><span class="s">&quot;Shuffle is &quot;</span> <span class="o">+</span> <span class="n">on_off</span><span class="p">[</span><span class="n">shuffle</span><span class="p">])</span></div><div class='line' id='LC55'>	<span class="k">print</span><span class="p">(</span><span class="s">&quot;Repeat All is &quot;</span> <span class="o">+</span> <span class="n">on_off</span><span class="p">[</span><span class="n">repeat_all</span><span class="p">])</span></div><div class='line' id='LC56'>	<span class="c"># print(&quot;Stereo playback is &quot; + on_off[play_stereo])</span></div><div class='line' id='LC57'><br/></div><div class='line' id='LC58'>	<span class="k">if</span> <span class="n">shuffle</span> <span class="o">==</span> <span class="bp">True</span><span class="p">:</span></div><div class='line' id='LC59'>		<span class="n">random</span><span class="o">.</span><span class="n">shuffle</span><span class="p">(</span><span class="n">file_list</span><span class="p">)</span></div><div class='line' id='LC60'>	<span class="k">with</span> <span class="nb">open</span><span class="p">(</span><span class="n">os</span><span class="o">.</span><span class="n">devnull</span><span class="p">,</span> <span class="s">&quot;w&quot;</span><span class="p">)</span> <span class="k">as</span> <span class="n">dev_null</span><span class="p">:</span></div><div class='line' id='LC61'>		<span class="k">for</span> <span class="n">filename</span> <span class="ow">in</span> <span class="n">file_list</span><span class="p">:</span></div><div class='line' id='LC62'>			<span class="k">print</span><span class="p">(</span><span class="s">&quot;Playing &quot;</span><span class="p">,</span><span class="n">filename</span><span class="p">)</span></div><div class='line' id='LC63'>			<span class="k">if</span> <span class="n">re</span><span class="o">.</span><span class="n">search</span><span class="p">(</span><span class="s">&quot;.pls$&quot;</span><span class="p">,</span> <span class="n">filename</span><span class="p">)</span> <span class="o">!=</span> <span class="bp">None</span><span class="p">:</span></div><div class='line' id='LC64'>				<span class="n">streamurl</span> <span class="o">=</span> <span class="n">parse_pls</span><span class="p">(</span><span class="n">filename</span><span class="p">,</span> <span class="mi">1</span><span class="p">)</span></div><div class='line' id='LC65'>				<span class="k">if</span> <span class="n">streamurl</span> <span class="o">!=</span> <span class="bp">None</span><span class="p">:</span></div><div class='line' id='LC66'>					<span class="k">print</span><span class="p">(</span><span class="s">&quot;streaming radio from &quot;</span> <span class="o">+</span> <span class="n">streamurl</span><span class="p">)</span></div><div class='line' id='LC67'>					<span class="n">subprocess</span><span class="o">.</span><span class="n">call</span><span class="p">([</span><span class="s">&quot;ffmpeg&quot;</span><span class="p">,</span><span class="s">&quot;-i&quot;</span><span class="p">,</span><span class="n">streamurl</span><span class="p">,</span><span class="s">&quot;-f&quot;</span><span class="p">,</span><span class="s">&quot;s16le&quot;</span><span class="p">,</span><span class="s">&quot;-acodec&quot;</span><span class="p">,</span><span class="s">&quot;pcm_s16le&quot;</span><span class="p">,</span><span class="s">&quot;-ac&quot;</span><span class="p">,</span> <span class="s">&quot;2&quot;</span> <span class="k">if</span> <span class="n">play_stereo</span> <span class="k">else</span> <span class="s">&quot;1&quot;</span> <span class="p">,</span><span class="s">&quot;-ar&quot;</span><span class="p">,</span><span class="s">&quot;44100&quot;</span><span class="p">,</span><span class="s">&quot;-&quot;</span><span class="p">],</span><span class="n">stdout</span><span class="o">=</span><span class="n">music_pipe_w</span><span class="p">,</span> <span class="n">stderr</span><span class="o">=</span><span class="n">dev_null</span><span class="p">)</span></div><div class='line' id='LC68'>			<span class="k">elif</span> <span class="n">re</span><span class="o">.</span><span class="n">search</span><span class="p">(</span><span class="s">&quot;.m3u$&quot;</span><span class="p">,</span> <span class="n">filename</span><span class="p">)</span> <span class="o">!=</span> <span class="bp">None</span><span class="p">:</span></div><div class='line' id='LC69'>				<span class="n">streamurl</span> <span class="o">=</span> <span class="n">parse_m3u</span><span class="p">(</span><span class="n">filename</span><span class="p">,</span> <span class="mi">1</span><span class="p">)</span></div><div class='line' id='LC70'>				<span class="k">if</span> <span class="n">streamurl</span> <span class="o">!=</span> <span class="bp">None</span><span class="p">:</span></div><div class='line' id='LC71'>					<span class="k">print</span><span class="p">(</span><span class="s">&quot;streaming radio from &quot;</span> <span class="o">+</span> <span class="n">streamurl</span><span class="p">)</span></div><div class='line' id='LC72'>					<span class="n">subprocess</span><span class="o">.</span><span class="n">call</span><span class="p">([</span><span class="s">&quot;ffmpeg&quot;</span><span class="p">,</span><span class="s">&quot;-i&quot;</span><span class="p">,</span><span class="n">streamurl</span><span class="p">,</span><span class="s">&quot;-f&quot;</span><span class="p">,</span><span class="s">&quot;s16le&quot;</span><span class="p">,</span><span class="s">&quot;-acodec&quot;</span><span class="p">,</span><span class="s">&quot;pcm_s16le&quot;</span><span class="p">,</span><span class="s">&quot;-ac&quot;</span><span class="p">,</span> <span class="s">&quot;2&quot;</span> <span class="k">if</span> <span class="n">play_stereo</span> <span class="k">else</span> <span class="s">&quot;1&quot;</span> <span class="p">,</span><span class="s">&quot;-ar&quot;</span><span class="p">,</span><span class="s">&quot;44100&quot;</span><span class="p">,</span><span class="s">&quot;-&quot;</span><span class="p">],</span><span class="n">stdout</span><span class="o">=</span><span class="n">music_pipe_w</span><span class="p">,</span> <span class="n">stderr</span><span class="o">=</span><span class="n">dev_null</span><span class="p">)</span></div><div class='line' id='LC73'>			<span class="k">else</span><span class="p">:</span></div><div class='line' id='LC74'>				<span class="n">subprocess</span><span class="o">.</span><span class="n">call</span><span class="p">([</span><span class="s">&quot;ffmpeg&quot;</span><span class="p">,</span><span class="s">&quot;-i&quot;</span><span class="p">,</span><span class="n">filename</span><span class="p">,</span><span class="s">&quot;-f&quot;</span><span class="p">,</span><span class="s">&quot;s16le&quot;</span><span class="p">,</span><span class="s">&quot;-acodec&quot;</span><span class="p">,</span><span class="s">&quot;pcm_s16le&quot;</span><span class="p">,</span><span class="s">&quot;-ac&quot;</span><span class="p">,</span> <span class="s">&quot;2&quot;</span> <span class="k">if</span> <span class="n">play_stereo</span> <span class="k">else</span> <span class="s">&quot;1&quot;</span> <span class="p">,</span><span class="s">&quot;-ar&quot;</span><span class="p">,</span><span class="s">&quot;44100&quot;</span><span class="p">,</span><span class="s">&quot;-&quot;</span><span class="p">],</span><span class="n">stdout</span><span class="o">=</span><span class="n">music_pipe_w</span><span class="p">,</span> <span class="n">stderr</span><span class="o">=</span><span class="n">dev_null</span><span class="p">)</span></div><div class='line' id='LC75'><br/></div><div class='line' id='LC76'><br/></div><div class='line' id='LC77'><br/></div><div class='line' id='LC78'><span class="k">def</span> <span class="nf">read_config</span><span class="p">():</span></div><div class='line' id='LC79'>	<span class="k">global</span> <span class="n">frequency</span></div><div class='line' id='LC80'>	<span class="k">global</span> <span class="n">shuffle</span></div><div class='line' id='LC81'>	<span class="k">global</span> <span class="n">repeat_all</span></div><div class='line' id='LC82'>	<span class="k">global</span> <span class="n">play_stereo</span></div><div class='line' id='LC83'>	<span class="k">try</span><span class="p">:</span></div><div class='line' id='LC84'>		<span class="n">config</span> <span class="o">=</span> <span class="n">configparser</span><span class="o">.</span><span class="n">ConfigParser</span><span class="p">()</span></div><div class='line' id='LC85'>		<span class="n">config</span><span class="o">.</span><span class="n">read</span><span class="p">(</span><span class="s">&quot;/pirateradio/pirateradio.config&quot;</span><span class="p">)</span></div><div class='line' id='LC86'><br/></div><div class='line' id='LC87'>	<span class="k">except</span><span class="p">:</span></div><div class='line' id='LC88'>		<span class="k">print</span><span class="p">(</span><span class="s">&quot;Error reading from config file.&quot;</span><span class="p">)</span></div><div class='line' id='LC89'>	<span class="k">else</span><span class="p">:</span></div><div class='line' id='LC90'>		<span class="n">play_stereo</span> <span class="o">=</span> <span class="n">config</span><span class="o">.</span><span class="n">get</span><span class="p">(</span><span class="s">&quot;pirateradio&quot;</span><span class="p">,</span> <span class="s">&#39;stereo_playback&#39;</span><span class="p">,</span> <span class="n">fallback</span><span class="o">=</span><span class="bp">True</span><span class="p">)</span></div><div class='line' id='LC91'>		<span class="n">frequency</span> <span class="o">=</span> <span class="n">config</span><span class="o">.</span><span class="n">get</span><span class="p">(</span><span class="s">&quot;pirateradio&quot;</span><span class="p">,</span><span class="s">&#39;frequency&#39;</span><span class="p">)</span></div><div class='line' id='LC92'>		<span class="n">shuffle</span> <span class="o">=</span> <span class="n">config</span><span class="o">.</span><span class="n">getboolean</span><span class="p">(</span><span class="s">&quot;pirateradio&quot;</span><span class="p">,</span><span class="s">&#39;shuffle&#39;</span><span class="p">,</span><span class="n">fallback</span><span class="o">=</span><span class="bp">False</span><span class="p">)</span></div><div class='line' id='LC93'>		<span class="n">repeat_all</span> <span class="o">=</span> <span class="n">config</span><span class="o">.</span><span class="n">getboolean</span><span class="p">(</span><span class="s">&quot;pirateradio&quot;</span><span class="p">,</span><span class="s">&#39;repeat_all&#39;</span><span class="p">,</span> <span class="n">fallback</span><span class="o">=</span><span class="bp">False</span><span class="p">)</span></div><div class='line' id='LC94'><br/></div><div class='line' id='LC95'><span class="k">def</span> <span class="nf">parse_pls</span><span class="p">(</span><span class="n">src</span><span class="p">,</span> <span class="n">titleindex</span><span class="p">):</span></div><div class='line' id='LC96'>	<span class="c"># breaking up the pls file in separate strings</span></div><div class='line' id='LC97'>	<span class="n">lines</span> <span class="o">=</span> <span class="p">[]</span></div><div class='line' id='LC98'>	<span class="k">with</span> <span class="nb">open</span><span class="p">(</span> <span class="n">src</span><span class="p">,</span> <span class="s">&quot;r&quot;</span> <span class="p">)</span> <span class="k">as</span> <span class="n">f</span><span class="p">:</span></div><div class='line' id='LC99'>		<span class="n">lines</span> <span class="o">=</span> <span class="n">f</span><span class="o">.</span><span class="n">readlines</span><span class="p">()</span></div><div class='line' id='LC100'><br/></div><div class='line' id='LC101'>	<span class="c"># and parse the lines</span></div><div class='line' id='LC102'>	<span class="k">if</span> <span class="n">lines</span> <span class="o">!=</span> <span class="bp">None</span><span class="p">:</span></div><div class='line' id='LC103'>		<span class="k">for</span> <span class="n">line</span> <span class="ow">in</span> <span class="n">lines</span><span class="p">:</span></div><div class='line' id='LC104'>			<span class="c"># search for the URI</span></div><div class='line' id='LC105'>			<span class="n">match</span> <span class="o">=</span> <span class="n">re</span><span class="o">.</span><span class="n">match</span><span class="p">(</span> <span class="s">&quot;^[ </span><span class="se">\\</span><span class="s">t]*file&quot;</span> <span class="o">+</span> <span class="nb">str</span><span class="p">(</span><span class="n">titleindex</span><span class="p">)</span> <span class="o">+</span> <span class="s">&quot;[ </span><span class="se">\\</span><span class="s">t]*=[ </span><span class="se">\\</span><span class="s">t]*(.*$)&quot;</span><span class="p">,</span> <span class="n">line</span><span class="p">,</span> <span class="n">flags</span><span class="o">=</span><span class="n">re</span><span class="o">.</span><span class="n">IGNORECASE</span> <span class="p">)</span></div><div class='line' id='LC106'>			<span class="k">if</span> <span class="n">match</span> <span class="o">!=</span> <span class="bp">None</span><span class="p">:</span></div><div class='line' id='LC107'>				<span class="k">if</span> <span class="n">match</span><span class="o">.</span><span class="n">group</span><span class="p">(</span> <span class="mi">1</span> <span class="p">)</span> <span class="o">!=</span> <span class="bp">None</span><span class="p">:</span></div><div class='line' id='LC108'>				<span class="c"># URI found, it&#39;s saved in the second match group</span></div><div class='line' id='LC109'>				<span class="c"># output the URI to the destination file</span></div><div class='line' id='LC110'>					<span class="k">return</span> <span class="n">match</span><span class="o">.</span><span class="n">group</span><span class="p">(</span> <span class="mi">1</span> <span class="p">)</span></div><div class='line' id='LC111'><br/></div><div class='line' id='LC112'>	<span class="k">return</span> <span class="bp">None</span></div><div class='line' id='LC113'><br/></div><div class='line' id='LC114'><span class="k">def</span> <span class="nf">parse_m3u</span><span class="p">(</span><span class="n">src</span><span class="p">,</span> <span class="n">titleindex</span><span class="p">):</span></div><div class='line' id='LC115'>	<span class="c"># create a list of strings, one per line in the source file</span></div><div class='line' id='LC116'>	<span class="n">lines</span> <span class="o">=</span> <span class="p">[]</span></div><div class='line' id='LC117'>	<span class="n">searchindex</span> <span class="o">=</span> <span class="nb">int</span><span class="p">(</span><span class="mi">1</span><span class="p">)</span></div><div class='line' id='LC118'>	<span class="k">with</span> <span class="nb">open</span><span class="p">(</span> <span class="n">src</span><span class="p">,</span> <span class="s">&quot;r&quot;</span> <span class="p">)</span> <span class="k">as</span> <span class="n">f</span><span class="p">:</span></div><div class='line' id='LC119'>&nbsp;&nbsp;		  <span class="n">lines</span> <span class="o">=</span> <span class="n">f</span><span class="o">.</span><span class="n">readlines</span><span class="p">()</span></div><div class='line' id='LC120'><br/></div><div class='line' id='LC121'>	<span class="k">if</span> <span class="n">lines</span> <span class="o">!=</span> <span class="bp">None</span><span class="p">:</span></div><div class='line' id='LC122'>		<span class="k">for</span> <span class="n">line</span> <span class="ow">in</span> <span class="n">lines</span><span class="p">:</span></div><div class='line' id='LC123'>		<span class="c"># search for the URI</span></div><div class='line' id='LC124'>			<span class="k">if</span> <span class="s">&#39;://&#39;</span> <span class="ow">in</span> <span class="n">line</span><span class="p">:</span></div><div class='line' id='LC125'>				<span class="k">if</span> <span class="n">searchindex</span> <span class="o">==</span> <span class="n">titleindex</span><span class="p">:</span></div><div class='line' id='LC126'>					<span class="k">return</span> <span class="n">line</span></div><div class='line' id='LC127'>				<span class="k">else</span><span class="p">:</span></div><div class='line' id='LC128'>					<span class="n">searchindex</span> <span class="o">+=</span> <span class="mi">1</span></div><div class='line' id='LC129'><br/></div><div class='line' id='LC130'>	<span class="k">return</span> <span class="bp">None</span></div><div class='line' id='LC131'><br/></div><div class='line' id='LC132'><br/></div><div class='line' id='LC133'><br/></div><div class='line' id='LC134'><span class="k">def</span> <span class="nf">daemonize</span><span class="p">():</span></div><div class='line' id='LC135'>	<span class="n">fpid</span><span class="o">=</span><span class="n">os</span><span class="o">.</span><span class="n">fork</span><span class="p">()</span></div><div class='line' id='LC136'>	<span class="k">if</span> <span class="n">fpid</span><span class="o">!=</span><span class="mi">0</span><span class="p">:</span></div><div class='line' id='LC137'>		<span class="n">sys</span><span class="o">.</span><span class="n">exit</span><span class="p">(</span><span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC138'><br/></div><div class='line' id='LC139'><br/></div><div class='line' id='LC140'><span class="k">def</span> <span class="nf">setup</span><span class="p">():</span></div><div class='line' id='LC141'>	<span class="c">#threading.Thread(target = open_microphone).start()</span></div><div class='line' id='LC142'><br/></div><div class='line' id='LC143'>	<span class="k">global</span> <span class="n">frequency</span></div><div class='line' id='LC144'>	<span class="n">read_config</span><span class="p">()</span></div><div class='line' id='LC145'>	<span class="c"># open_microphone()</span></div><div class='line' id='LC146'>	<span class="n">run_pifm</span><span class="p">()</span></div><div class='line' id='LC147'><br/></div><div class='line' id='LC148'><br/></div><div class='line' id='LC149'><span class="k">def</span> <span class="nf">run_pifm</span><span class="p">(</span><span class="n">use_audio_in</span><span class="o">=</span><span class="bp">False</span><span class="p">):</span></div><div class='line' id='LC150'>	<span class="k">global</span> <span class="n">fm_process</span></div><div class='line' id='LC151'>	<span class="k">with</span> <span class="nb">open</span><span class="p">(</span><span class="n">os</span><span class="o">.</span><span class="n">devnull</span><span class="p">,</span> <span class="s">&quot;w&quot;</span><span class="p">)</span> <span class="k">as</span> <span class="n">dev_null</span><span class="p">:</span></div><div class='line' id='LC152'>		<span class="n">fm_process</span> <span class="o">=</span> <span class="n">subprocess</span><span class="o">.</span><span class="n">Popen</span><span class="p">([</span><span class="s">&quot;/root/pifm&quot;</span><span class="p">,</span><span class="s">&quot;-&quot;</span><span class="p">,</span><span class="nb">str</span><span class="p">(</span><span class="n">frequency</span><span class="p">),</span><span class="s">&quot;44100&quot;</span><span class="p">,</span> <span class="s">&quot;stereo&quot;</span> <span class="k">if</span> <span class="n">play_stereo</span> <span class="k">else</span> <span class="s">&quot;mono&quot;</span><span class="p">],</span> <span class="n">stdin</span><span class="o">=</span><span class="n">music_pipe_r</span><span class="p">,</span> <span class="n">stdout</span><span class="o">=</span><span class="n">dev_null</span><span class="p">)</span></div><div class='line' id='LC153'><br/></div><div class='line' id='LC154'>		<span class="c">#if use_audio_in == False:</span></div><div class='line' id='LC155'>		<span class="c">#else:</span></div><div class='line' id='LC156'>		<span class="c">#	fm_process = subprocess.Popen([&quot;/root/pifm2&quot;,&quot;-&quot;,str(frequency),&quot;44100&quot;], stdin=microphone_pipe_r, stdout=dev_null)</span></div><div class='line' id='LC157'><br/></div><div class='line' id='LC158'><span class="k">def</span> <span class="nf">record_audio_input</span><span class="p">():</span></div><div class='line' id='LC159'>	<span class="k">return</span> <span class="n">subprocess</span><span class="o">.</span><span class="n">Popen</span><span class="p">([</span><span class="s">&quot;arecord&quot;</span><span class="p">,</span> <span class="s">&quot;-fS16_LE&quot;</span><span class="p">,</span> <span class="s">&quot;--buffer-time=50000&quot;</span><span class="p">,</span> <span class="s">&quot;-r&quot;</span><span class="p">,</span> <span class="s">&quot;44100&quot;</span><span class="p">,</span> <span class="s">&quot;-Dplughw:1,0&quot;</span><span class="p">,</span> <span class="s">&quot;-&quot;</span><span class="p">],</span> <span class="n">stdout</span><span class="o">=</span><span class="n">microphone_pipe_w</span><span class="p">)</span></div><div class='line' id='LC160'><br/></div><div class='line' id='LC161'><span class="k">def</span> <span class="nf">open_microphone</span><span class="p">():</span></div><div class='line' id='LC162'>	<span class="k">global</span> <span class="n">fm_process</span></div><div class='line' id='LC163'>	<span class="n">audio_process</span> <span class="o">=</span> <span class="bp">None</span></div><div class='line' id='LC164'>	<span class="k">if</span> <span class="n">os</span><span class="o">.</span><span class="n">path</span><span class="o">.</span><span class="n">exists</span><span class="p">(</span><span class="s">&quot;/proc/asound/card1&quot;</span><span class="p">):</span></div><div class='line' id='LC165'>		<span class="n">audio_process</span> <span class="o">=</span> <span class="n">record_audio_input</span><span class="p">()</span></div><div class='line' id='LC166'>		<span class="n">run_pifm</span><span class="p">(</span><span class="n">merge_audio_in</span><span class="p">)</span></div><div class='line' id='LC167'>	<span class="k">else</span><span class="p">:</span></div><div class='line' id='LC168'>		<span class="n">run_pifm</span><span class="p">()</span></div><div class='line' id='LC169'><br/></div><div class='line' id='LC170'><br/></div><div class='line' id='LC171'><br/></div><div class='line' id='LC172'><span class="n">main</span><span class="p">()</span></div><div class='line' id='LC173'><br/></div></pre></div></td>
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
      <li>&copy; 2014 <span title="0.06163s from github-fe125-cp1-prd.iad.github.net">GitHub</span>, Inc.</li>
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

