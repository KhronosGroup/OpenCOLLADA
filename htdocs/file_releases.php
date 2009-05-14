<?php require('../simplepie.inc'); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
       "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en">
<head>

<script type="text/javascript">
    <!--
    if (navigator.appName.indexOf("Explorer") != -1){
        if (navigator.appVersion.indexOf("MSIE 6.0") != -1){
            document.write("<link href=\".\/css\/styleIE6.css\" rel=\"stylesheet\" type=\"text\/css\"\/>");
        }
        else{
            document.write("<link href=\".\/css\/style.css\" rel=\"stylesheet\" type=\"text\/css\"\/>");
        }
    }
    else{
        document.write("<link href=\".\/css\/style.css\" rel=\"stylesheet\" type=\"text\/css\"\/>");
    }
    -->
</script>

<title>COLLADA Plug-ins</title>
<meta name="description" content="COLLADA Plug-ins for Max an Maya" />
<meta name="keywords" content="COLLADA, Khronos, 3D, visualization, Max, Maya, graphics, rendering, download, bug, tracker, plugin, plug-in, sourceforge, version, current, documentation" />
<meta name="robots" content="index, follow" />
<meta http-equiv="Content-type" content="text/html;charset=iso-8859-1"/>
<link rel="alternate" type="application/rss+xml" title="RSS" href="https://sourceforge.net/export/rss2_projnews.php?group_id=136478" />

</head>
<body><p><a name="top"></a></p>
	<div id="wrap">
		<div id="header">
			<div class="head_c"></div>
			<div class="head_l"></div>
			<div class="head_content">
				<div id="logo">
					<a href="http://colladamaya.sourceforge.net/"><img src="images/collada_logo.gif" alt="COLLADA Logo"/></a>
				</div>
				<div id="logotxt">
					<h1>COLLADA Plug-ins for Maya and 3ds Max</h1>
				</div>
			</div>
			<div class="head_r"></div>
		</div>
		<div id="menu">
			<div class="main_content">
				<div class="menu_content">
					<div id="navigation_l"></div>
						<ul id="navigation">
							<!-- 
							<li><a href="http://colladamaya.wiki.sourceforge.net/" title="A Documentation about COLLADA Plug-ins">Wiki</a></li>
							 -->
							<li><a href="http://sourceforge.net/forum/?group_id=136478" title="Source Forge Forums for COLLADA Plug-ins">Forums</a></li>
							<li><a href="http://sourceforge.net/project/screenshots.php?group_id=136478" title="Screenshots of COLLADA Plug-ins">Screenshots</a></li>
							<li><a href="http://sourceforge.net/scm/?type=svn&group_id=254488" title="Browse the colladamaya code repository">Code</a></li>
							<li><a href="http://sourceforge.net/project/showfiles.php?group_id=136478" title="Download the latest Version of COLLADA Plug-ins">Downloads</a></li>
							<li><a href="http://sourceforge.net/tracker/?group_id=136478" title="Tell us a bug">BugTracker</a></li>
							<li><a href="http://sourceforge.net/search/?group_id=136478&amp;type_of_search=pervasive" title="SF.net Search">Search</a></li>
						</ul>
					<div id="navigation_r"></div>
				</div>
			</div>
		</div>
		<div id="main">
			<div class="main_content">
				<div class="sidebar">
					<div class="sidebar_nav">
						<div class="nav_head">
							<h3>Menu</h3>
						</div>
						<div class="nav_main">
							<ul>
								<li><a href="index.php" title="Project Summary">Project Summary</a></li>
								<li><a href="news.php" title="News">News</a></li>
								<li><a href="file_releases.php" title="File Releases">File Releases</a></li>
								<li><a href="osx_installation_help/index.php" title="Mac OS X Installation">Mac OS X Installation</a></li>							</ul>
						</div>
						<div class="nav_foot"></div>
					</div>
					
					<div class="sidebar_nav">
						<div class="nav_head">

							<h3>Project Status</h3>
						</div>
						<div class="nav_main">
							<ul>
								<!-- <li>Status: 93%</li> -->
								<li>Last release:<br/>
								 
								<?php

									$projfiles = new SimplePie();
									$projfiles->enable_cache(false);
									$projfiles->set_feed_url('http://sourceforge.net/export/rss2_projfiles.php?group_id=136478');
									$projfiles->init();
									$projfiles->handle_content_type();
									if ($projfiles->data) {

										$item = $projfiles->get_item(0);
										list($version, $head) =  split("released", $item->get_title());

										//echo $version;

										// if a part of the Version Sting overlaps the "Project Status"
										// Box, the whole site looks bad with IE.
										$token = strtok($version, " ");
										while ($token != false)
										{
											if (strlen($token) >= 20) {
												echo chunk_split($token, 20, "<br/>");
											} else {
												echo "$token ";
											}
											$token = strtok(" ");
										}
										
									}

								?>

								</li>
							</ul>
						</div>
						<div class="nav_foot"></div>
					</div>
					
					<div class="sidebar_nav">
						<div class="sub_single">
							<h3><a href="https://sourceforge.net/project/platformdownload.php?group_id=136478" title="Download last release">Download now!</a></h3>
						</div>
					</div>
					
					<div class="sidebar_nav">
						<div class="nav_head">
							<h3>Links</h3>
						</div>
						<div class="nav_main">
							<p><a href="http://sourceforge.net"><img src="http://sflogo.sourceforge.net/sflogo.php?group_id=136478&amp;type=1" width="88" height="31" border="0" alt="SourceForge.net Logo" /></a></p>
							<p><a href="http://collada.org/"><img src="images/collada_small.gif" alt="COLLADA-Logo"/></a></p>
						</div>
						<div class="nav_foot"></div>
					</div>
				</div>
				
				<div class="content">
					<div class="content_inner">

						<div class="content_head">
							<h2><a name="file">File Releases</a></h2>
							<div class="head_menu"><p><a href="#top"><img src="images/upArrow.png" alt="Top"/> Top</a> | <a href="https://sourceforge.net/export/rss2_projfiles.php?group_id=136478"><img src="images/rss.gif" title="File Releases RSS Feed" alt="rssFeed"/></a></p></div>
						</div>
						<div class="content_main">
							
							<?php
							$projfiles = new SimplePie();
							$projfiles->enable_cache(false);
							$projfiles->set_feed_url('http://sourceforge.net/export/rss2_projfiles.php?group_id=136478');
							$projfiles->init();
							$projfiles->handle_content_type();
							if ($projfiles->data) { ?>
							
							<?php
							    $max = $projfiles->get_item_quantity(5);
							    for ($x = 0; $x < $max; $x++) {
								    $item = $projfiles->get_item($x);
							    ?>
								<h3>
								    <a href="<?php echo $item->get_permalink(); ?>">
									<?php echo $item->get_title(); ?>
								    </a>
								</h3>
								<div class="head3_menu">
									<p>
										<a href="<?php echo $item->add_to_delicious(); ?>"><img src="images/delLogo.png" alt="Del.icio.us Logo" title="Del.icio.us" /></a> 
										<a href="<?php echo $item->add_to_digg(); ?>"><img src="images/diggLogo.gif" alt="Digg this! Logo" title="Digg this!" /></a> 
										<a href="<?php echo $item->add_to_newsvine(); ?>"><img src="images/newsvLogo.gif" alt="Newsvine Logo" title="Newsvine" /></a>
									</p>
								</div>
								<!-- <p><?php echo $item->get_date('j M Y'); ?></p> -->
								<?php 
								$camp = str_replace("&", "&amp;", $item->get_description());
								
								//echo '<p>'.$camp.'</p>';

								// print file list formatted
								echo '<p>';
								$tokens = split("),", $camp);
								$arrayLength = count($tokens);
								foreach ($tokens as $i => $value) {
									if ($i == 0) {
										// first entry, print "Includes files:" in separate line.
										echo str_replace("files:", "files:<br/>", $tokens[$i]);
										if ($i == $arrayLength-1) {
											// only one file in list.
											echo "<br/>";
										} else {
											echo "),<br/>";
										}
									} else if ($i == $arrayLength-1) {
										// last entry in list.
										echo "$tokens[$i]<br/>";
									} else {
										// default case.
    									echo "$tokens[$i]),<br/>";
									}
								}
								echo '</p>';
								?>
								<br/>
							    <?php } ?>
							<?php } ?>
                                                        
							
						</div>
						<div class="content_foot"></div>

					</div>
				</div>
			</div>
		</div>
		<div id="footer">
			<div class="footer_content">
				<p>Copyright &copy; 2009 NetAllied Systems GmbH
				</p>
			</div>
		</div>
	</div>
</body>
</html>
