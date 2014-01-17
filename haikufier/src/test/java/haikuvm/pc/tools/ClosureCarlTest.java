/**
 * 
 */
package haikuvm.pc.tools;

import static org.junit.Assert.*;
import java.io.File;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.logging.ConsoleHandler;
import java.util.logging.FileHandler;
import java.util.logging.Handler;
import java.util.logging.Level;
import java.util.logging.Logger;


import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

/**
 * @author CDN
 *
 */
public class ClosureCarlTest {

	/**
	 * @throws java.lang.Exception
	 */
	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
	}
	URLClassLoader classLoader;
	ClosureCarl instance;
	/**
	 * @throws java.lang.Exception
	 */
	@AfterClass
	public static void tearDownAfterClass() throws Exception {
	}

	/**
	 * @throws java.lang.Exception
	 */
	@Before
	public void setUp() throws Exception {
		// Split the path on ; (semicolon) and on the path.separator.
		// Why also on ; (semicolon) is not very clear.
		/*
		String path[]=(HaikuVM.bootclasspath+System.getProperty("path.separator")
				+HaikuVM.classpath).split("[;"+System.getProperty("path.separator")+"]+");
		 */
		// For testing:
		// paths1 are the nxt paths (lower priority than paths2)
		// paths2 are the highest priority.
		// IMPORTANT: ClosureCarl will reverse the normal Java classloader sequence:
		// ClosureCarl will take latest classloader as highest priority.
		String paths1[]={
				"/D:\\downloads\\HaikuVM-1.1.0-rc3\\haikuVM\\lib\\nxt\\classes.jar"
		};
		// Higher priority
		String paths2[]={
				"/D:\\git\\HaikuVM2\\arduino-carl-1\\bin\\",
				"/D:\\git\\HaikuVM2\\gallerie\\bin\\",
				"/D:\\Users\\cdn\\workspace\\examples\\bin\\",
				"/D:\\Users\\cdn\\workspace\\haikuRT\\bin\\java\\lang\\"
		};
		// Our classloader needs URLs as the classpath.
		// Any URL ending in / is supposed to be a directory,
		// Any URL not ending in / is supposed to be a jar file
		URLClassLoader classLoader=null;
		for (String[] paths:new String[][]{paths1,paths2}) {
			URL[] urls=new URL[paths.length];
			// Make the file names into urls by prefixing them with file://
			for (int i=0;i<paths.length;i++) {
				try {
					urls[i]=new URL("file://"+paths[i]);
				} catch (MalformedURLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			classLoader=new URLClassLoader(urls, classLoader);
		}
		//classLoader=new URLClassLoader(urls);
		//instance=new ClosureCarl(classLoader);
		instance=new ClosureCarl(classLoader);
	}

	/**
	 * @throws java.lang.Exception
	 */
	@After
	public void tearDown() throws Exception {
	}

	/**
	 * Test method for {@link haikuvm.pc.tools.ClosureCarl#visitMethod(int, java.lang.String, java.lang.String, java.lang.String, java.lang.String[])}.
	 */
	@Test
	public void testVisitMethod() {
		fail("Not yet implemented");
	}

	/**
	 * Test method for {@link haikuvm.pc.tools.ClosureCarl#ClosureCarl(java.lang.ClassLoader)}.
	 */
	@Test
	public void testClosureCarl() {
		fail("Not yet implemented");
	}

	/**
	 * Test method for {@link haikuvm.pc.tools.ClosureCarl#scan(java.lang.String)}.
	 * @throws ClassNotFoundException 
	 */
	@Test
	public void testScan() throws ClassNotFoundException {
		//String classname="lejos.addon.keyboard.KeyEvent";
		String classname="nl.vandenzen.arduino.lcdtest1.LcdTest";
		// Set log level to a nice debug level
		Level level=Level.FINEST;
		Logger logger=Logger.getLogger("haikuvm.pc.tools");
		logger.setLevel(level);
		// use parent handlers?
		if (logger.getUseParentHandlers()) {
			logger=logger.getParent();
		}
		Handler[] handlers=logger.getHandlers();
		for (Handler handler:handlers) {
			if (handler instanceof ConsoleHandler) {
				ConsoleHandler ch=(ConsoleHandler) handler;
				ch.setLevel(level);
			}
		}
		// output to file, settings are in run configuration, something like this:
		// -Djava.util.logging.config.file=D:\\Users\\cdn\\workspace\\haikufier\\src\\test\\java\\logging.properties
		// -classpath D:\\Users\\cdn\\workspace\\lib\\pc\\*
		logger=Logger.getLogger("haikuvm.pc.tools");
		String a=System.getProperty("java.util.logging.config.file");
		if (a.equals("hoi")) {
			a="bla";
		}
		instance.scan(new Member(classname.replace(".","/"), "", ""));
		// Outputdirectory
		File outputdirectory=new File("D:\\tmp\\haikuoutputcarl");
		if (!a.equals("hoi")) outputdirectory.mkdirs();
		instance.createClassFiles(outputdirectory);
		
		instance.listClinitsInOrder();
		
		instance.showTreeInNewFrame();
	}

	/**
	 * Test method for {@link haikuvm.pc.tools.ClosureCarl#root(java.lang.String)}.
	 */
	@Test
	public void testRoot() {
		fail("Not yet implemented");
	}

	/**
	 * Test method for {@link haikuvm.pc.tools.ClosureCarl#isMarked(java.lang.String)}.
	 */
	@Test
	public void testIsMarked() {
		fail("Not yet implemented");
	}

}
/*
-Djava.util.logging.config.file=${git_dir}\\haikufier\\src\\test\\java\\logging.properties -classpath ${git_dir}\\lib\\pc\\*
*/