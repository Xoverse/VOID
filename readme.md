# **IMPORTANT NOTICE**

The Xoverse, Evil Buddy, Akii, or the Xoverse's member are **NOT** responsible for any damage dealt to any machine.

# VOID

by XOVERSE

## What is VOID ?

Void is a Trojan made by Evil Buddy in C++

## How can I remove it from my machine ?

It depends of it's state. Whether what's it's state, it's easy to remove it

## Can I run it without being an administrator ?

You probably can, but it might error. Look at these solutions:
1. You can modify the source code to remove the actions that needs administrator permissions (copy self and modify regedit)
2. Run it with the argument `-v` (which is used when you restart the computer)

### The payload wasn't ran (lack of permissions or the computer hasn't been shutdown)

1. Go to `C:\`

2. Delete `VOID.exe`

3. Open the registry editor (`C:\Windows\System32\regedit.exe`)

4. Navigate to `HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Run`

5. Delete the key named `CHARA IS HERE`

### The payload was ran

1. Close `VOID.exe` using the CMD (as admin) or the task manager
	Using the CMD, you can close it usign this command: `taskkill /f /im VOID.exe`
2. Same steps as before