<!-- vscode-markdown-toc -->
* 1. [Creating User Accounts](#CreatingUserAccounts)
	* 1.1. [Adding users with adduser](#Addinguserswithadduser)
	* 1.2. [Setting user defaults](#Settinguserdefaults)
	* 1.3. [Modifying users with usermod](#Modifyinguserswithusermod)
	* 1.4. [Deleting users with deluser](#Deletinguserswithdeluser)
* 2. [Understanding Group Accounts](#UnderstandingGroupAccounts)
	* 2.1. [Using group accounts](#Usinggroupaccounts)
	* 2.2. [Creating group accounts](#Creatinggroupaccounts)
* 3. [Managing Users in the Enterprise](#ManagingUsersintheEnterprise)
	* 3.1. [Setting permissions with Access Control Lists](#SettingpermissionswithAccessControlLists)
		* 3.1.1. [Setting ACLs with setfacl](#SettingACLswithsetfacl)
		* 3.1.2. [Setting default ACLs](#SettingdefaultACLs)
		* 3.1.3. [Enabling ACLs](#EnablingACLs)
		* 3.1.4. [Adding directories for users to collaborate](#Addingdirectoriesforuserstocollaborate)
		* 3.1.5. [Creating group collaboration directories (set GID bit)](#CreatinggroupcollaborationdirectoriessetGIDbit)
		* 3.1.6. [Creating restricted deletion directories (sticky bit)](#Creatingrestricteddeletiondirectoriesstickybit)
* 4. [Centralizing User Accounts](#CentralizingUserAccounts)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->




##  1. <a name='CreatingUserAccounts'></a>Creating User Accounts

###  1.1. <a name='Addinguserswithadduser'></a>Adding users with adduser

- Best way is using `adduser`
  - Ubuntu recomends `adduser` and `deluser` (more friendly and interactive) rather than `useradd` and `userdel`
- It uses `sudo adduser <username>`
  - Reads the `/etc/login.defs` and `/etc/adduser.conf` files to get default values
to use when creating accounts.
- Checks command-line parameters to find out which default values to override:
  - `--home`
  - `--ingroup`
  - `--uid`
  - `--shell`
- Creates a new user entry in the `/etc/passwd` and `/etc/shadow` files based on the
default values and command-line parameters.
- Creates any necessary entries for new groups in the `/etc/group` file.
- Creates a home directory based on the user’s name in the `/home/<username>` directory.
  - Copies any files located within the `/etc/skel` directory to the new home directory.
    - **This usually includes login and application startup scripts.**

###  1.2. <a name='Settinguserdefaults'></a>Setting user defaults
- The `adduser` command determines the default values for new accounts by reading the `/etc/login.defs` and `/etc/adduser.conf` files.
- Altering a default value is as simple as editing the value associated with a keyword and saving the file before running the `adduser` command.

###  1.3. <a name='Modifyinguserswithusermod'></a>Modifying users with usermod

###  1.4. <a name='Deletinguserswithdeluser'></a>Deleting users with deluser

##  2. <a name='UnderstandingGroupAccounts'></a>Understanding Group Accounts

###  2.1. <a name='Usinggroupaccounts'></a>Using group accounts

###  2.2. <a name='Creatinggroupaccounts'></a>Creating group accounts

##  3. <a name='ManagingUsersintheEnterprise'></a>Managing Users in the Enterprise

###  3.1. <a name='SettingpermissionswithAccessControlLists'></a>Setting permissions with Access Control Lists

####  3.1.1. <a name='SettingACLswithsetfacl'></a>Setting ACLs with setfacl

####  3.1.2. <a name='SettingdefaultACLs'></a>Setting default ACLs

####  3.1.3. <a name='EnablingACLs'></a>Enabling ACLs

####  3.1.4. <a name='Addingdirectoriesforuserstocollaborate'></a>Adding directories for users to collaborate

####  3.1.5. <a name='CreatinggroupcollaborationdirectoriessetGIDbit'></a>Creating group collaboration directories (set GID bit)

####  3.1.6. <a name='Creatingrestricteddeletiondirectoriesstickybit'></a>Creating restricted deletion directories (sticky bit)

##  4. <a name='CentralizingUserAccounts'></a>Centralizing User Accounts