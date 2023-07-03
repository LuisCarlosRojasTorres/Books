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
- `usermod` changes account parameters. It has the follwing options:
  - `-c <userName>`: Change the description associated with the user account.
    - Use `" "` multiple words     
  - `-d <home_dir>`: change the home directory to use for the account
  - `-e <expire_date>`: change the home directory to use for the account 
  - `-g <groupName>`: change the primary group e.g. `-g sudo
  - `-G <GroupList>`: Set the user’s secondary groups to the supplied comma-separated list of groups. If the user is already in at least one group besides the user’s private group, you must add the `-a` option as well (`-Ga`). If not, the user belongs to only the new set of groups and loses membership to any previous groups.
    - e.g. `usermod -Ga app_users, temporal, LBloOd`
  - `-s <shell>`: specify a different command sell to use for this account. e.g. `-s bash`
  - `-u <user-id>`: change the userID number for the account. e.g.  `-u 6969`
    
###  1.4. <a name='Deletinguserswithdeluser'></a>Deleting users with deluser
- To delete the user and its home directory:
  - `deluser --remove-home LBloOd`
- To dele only the account:
  - `deluser LBloOd`

##  2. <a name='UnderstandingGroupAccounts'></a>Understanding Group Accounts
- Groups are useful if you want to share a set of files with multiple users. You can create a group and configure the set of files to be associated with that group
- Only `root` user can assign users to groups.

###  2.1. <a name='Usinggroupaccounts'></a>Using group accounts
- Every user is assigned to a primary group. In Ubuntu, by default, that group is a new group
with the same name as the user.
- The primary group is indicated by the number in the third field of each entry in the `/etc/passwd` file;
- Let’s turn to the `LBloOd` user and group accounts for examples. Here are a few facts about using groups:
  - When `LBloOd` creates a file or directory, by default, that file or directory is assigned to `LBloOd`’s primary group (also called `LBloOd`).
  - The user `LBloOd` can’t add herself to a supplementary group. She can’t even add another user to her `LBloOd` group. Only someone with `root` privilege can assign users to groups.


###  2.2. <a name='Creatinggroupaccounts'></a>Creating group accounts
- A `root` user, can create new groups from the command line with the `addgroup` command.
  - e.g. `addgroup players` : Players groups is created with the next available `groupID`
  - e.g. `addgroup --gid 1234 players`: Players groups is created with the `groupID` 1234.
