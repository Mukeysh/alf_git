<?php 
/**
 * Interface for a package handler
 * @author rbrandon
 *
 */
interface scholar_software_handler{
	//Return the packages found at the target url
	public function getPackages();
	
	//Return the active package
  public function getPackage();
	
	/**
   * Alter a project node before it is saved
   * @param $node
   */
  public function alterProject(&$node);
}