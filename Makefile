snap:
	sudo pacman -S snapd 
	sudo systemctl enable --now snapd.socket
	sudo snap install discord
	sudo snap install code --classic
	sudo snap install node --classic
	sudo snap install goland --classic
	sudo snap install spotify

flatpak:
	pamac install flatpak

docker:
	sudo pacman -S docker
	sudo systemctl enable --now docker

go:
	sudo pacman -S go

chrome:
	sudo pacman -S --needed base-devel git
	git clone https://aur.archlinux.org/yay-git.git
	cd yay
	makepkg -si
	yay -S google-chrome
	yay -Syu

chrome2:
	sudo pacman -S --needed base-devel git
	git clone https://aur.archlinux.org/google-chrome.git
	cd google-chrome
	makepkg -si
	git pull
	makepkg -si