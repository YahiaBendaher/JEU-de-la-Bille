
# ⚙️ Jeu de la Bille – mbed LPC1768


## 📝 Description

Un mini-jeu développé en **C++ pour microcontrôleur mbed LPC1768**, où une **bille** se déplace sur l’écran **C12832 LCD** à l’aide de **boutons directionnels**.  
Le but est de **rejoindre la cible avant la fin du temps imparti**, avec un système de **score et niveaux progressifs**.

---

## 🎯 Objectif

- Dirige la bille avec les boutons `haut`, `bas`, `gauche`, `droite`
- Atteins la cible avant la fin du temps pour gagner des points
- Plus tu avances, moins tu as de temps !

---

## 🚀 Fonctionnalités

- 🎮 Contrôle via entrées numériques (boutons)
- 📺 Affichage graphique avec `C12832`
- ⏱️ Gestion de score, timer, niveaux
- 🎯 Génération aléatoire de cible
- 📈 Difficulté progressive (temps réduit à chaque niveau)

---

## ⚙️ Matériel utilisé

- 💡 [mbed LPC1768](https://os.mbed.com/platforms/mbed-LPC1768/)
- 📟 [C12832 LCD display](https://os.mbed.com/components/C12832-LCD/)

---

 🛠️ Technologies & Librairies
- [C++](https://fr.cppreference.com/w/) embarqué
- [mbed SDK](https://os.mbed.com/mbed-os/)

##🧑‍💻 Comment compiler & flasher
1 - Ouvre le projet sur l’IDE mbed en ligne ou via Mbed CLI.

2 - Sélectionne le target LPC1768.

3 - Compile.

4 - Flash le .bin sur ta carte via USB.
