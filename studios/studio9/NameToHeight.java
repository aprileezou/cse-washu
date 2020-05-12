package studio9;

import java.util.HashMap;
import java.util.Map;

import cse131.ArgsProcessor;
import cse131.NotYetImplementedException;

public class NameToHeight {
	/**
	 * Construct and fill a map with your studio group members' names, each
	 * associated with his or her height.
	 * 
	 * Construct an ArgsProcessor and loop asking the args processor for a name to
	 * lookup the height. When the user cancels (that is: when args processor
	 * returns null), break from the loop. Otherwise, loop up the name in the map
	 * and output the results. Be sure to handle the case where the map does not
	 * contain a specified name.
	 */
	public static void main(String[] args) {
		ArgsProcessor ap = new ArgsProcessor(args);
		
		Map<String, Integer> mapNameToHeight = new HashMap<String, Integer>();
		mapNameToHeight.put("April", 162);
		mapNameToHeight.put("Yuwen", 160);
		
		String name = ap.nextString("The name?");
		System.out.println(name + "? " + mapNameToHeight.get(name));
		
	}
}
