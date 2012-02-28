Drupal.behaviors.biocvAutoDownload = function (context) {
  setTimeout(Drupal.biocvStartAutoDownload, 3000);
}

Drupal.biocvStartAutoDownload = function() {
	if (Drupal.settings.biocvAutoDownload['download_link_class']) {
		window.location = $("."+Drupal.settings.biocvAutoDownload['download_link_class']).attr('href');
		
		//Don't Run Again
		Drupal.settings.biocvAutoDownload['download_link_class'] = false;
    }
}