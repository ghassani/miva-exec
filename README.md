# Miva Library Test

Just playing around with adding functionality to Miva Scripting language. In this Shared Library you can execute system commands with a newly created miva script function 'exec'

There are pre-built DLL/SO files in the release folder.

If you have access to configure the Miva VM, you can add the following to your mivavm.conf:

<BUILTIN-LIB LIBRARY = "/path/to/test.so">
<BUILTIN-LIB LIBRARY = "C:\path\to\test.dll">

Or just drop it in the builtin directory for the VM.

---
Found out the basis of how to do this from this post:

http://extranet.mivamerchant.com/forums/archive/index.php/t-151.html