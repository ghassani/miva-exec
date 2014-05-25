# Miva Exec

This Builtin Library adds exec function to Miva Script VM allowing you to execute system/shell commands.

There are pre-built DLL/SO files in the bin folder.

If you have access to configure the Miva VM, you can add the following to your mivavm.conf:

<BUILTIN-LIB LIBRARY = "/path/to/mivaexec.so">
<BUILTIN-LIB LIBRARY = "C:\path\to\MivaExec.dll">

Or just drop it in the builtin directory for the VM.
