# Guida per collaborare al progetto Controllo Accessi Gulli

### :white_small_square: 1. Creare un account su  Github ( https://github.com/join )
___
### :white_small_square: 2. SW da scaricare sul proprio PC

- [Arduino IDE SW ] (https://www.arduino.cc/en/Main/Software) (:raised_hand: chi ha già scritto e compilato almeno uno sketch su Arduino ce lo dovrebbe già avere )
- [Git - distributed version control system ] (https://git-scm.com/)
- [Una semplice guida a Git ] (http://rogerdudler.github.io/git-guide/index.it.html) (Opzionale)

___

### :white_small_square: 3.  Clonare un progetto Github su Github
Dopo aver eseguito l'accesso con il proprio account Github cercare il repository principale di progetto *controllo_accessi_gulli* (https://github.com/gulli-livorno/controllo_accessi_gulli) ed eseguire un **Fork** del repository.
Questo creerà una copia del repository sul proprio account Github. E' già possibile lavorare al progetto on-line andando a modificare i singoli file.

:warning: *Per lo sviluppo di SW comunque non è indicato lavorare direttamente sul repository on line ma è preferibile lavorare su una copia locale e poi aggiornare il repository remoto*. L'editing di file online è comunque utile per aggiornare velocemente i file della documentazione. Vedi punto 4.

####  3a. Fare il **commit** di un file modificato on-line
Quando un file è stato modificato direttamente sul sito è possibile registrare le modifiche per creare una storia del progetto. Per farlo esiste il tasto **[ Commit Changes ]** in fondo all'editor. E' buona norma inserire un messaggio di commit per ricordarsi quali modifiche sono state fatte sul file. Su Github per salvare le modifiche ad un file è comunque necessario fare un commit.

___

### :white_small_square: 4. Clonare un progetto Github sul proprio PC
Dopo aver installato Git sul proprio PC posizionarsi nel file system dove si vuole che venga creata la directory di progetto.
Eseguire il comando: 

 `git clone https://git_hub_user_name@github.com/git_hub_user_name/controllo_accessi_gulli`
 
 dove *git_hub_user_name* è lo user name dell'account Github creato in precedenza.
Sarà creata una directory con il contenuto del progetto come esiste su Github nell'account personale creato all'inizio. Adesso è possibile lavorare in locale usando gli strumenti di sviluppo preferiti.
####    4a. Fare il commit di un file modificato
Prima di consegnare le nostre modifiche è necessario confiurare git con le nostre credenziali:

`git config --global user.email "you@example.com"`

`git config --global user.name "Your Name"`

Quando un file è stato modificato ed un piccolo progresso od obiettivo sono stati raggiunti si possono registrare le modifiche per creare una storia del progetto nel repository locale. Eseguire il comando:

`git commit -a -m "messaggio di commit"`

####    4b. Aggiornare il proprio repository su Github con il lavoro fatto in locale
eseguire il comando 

`git push origin master`

In questo modo il repository remoto sarà sincronizzato con quello locale (saranno richiesti user name e password del vostro account github per l'operazione di **push**).

####    4c. Conflitto con un file sul repository su GitHub
Se un file è stato modificato e caricato su GitHub mentre noi modificavamo i files sul nostro PC, al momento del del **push** il sistema si accorgerà del conflitto ed impedirà il caricamento. Anche il messaggio di errore suggerirà di effettuare un

`git pull`

per integrare le modifiche già caricate sul server con la nostra copia locale.

___

### :white_small_square: 5. Sincronizare il proprio repository remoto con il repository principale di progetto entrambi su Github
Non è possibile farlo direttamente da Github ma bisogna passare attraverso il proprio repository locale sul PC
Per prima cosa aggiungere il repository principale di progetto come un altro repository remoto collegato al repository locale:

`git remote add upstream https://github.com/gulli-livorno/controllo_accessi_gulli` 

in questo modo abbiamo aggiunto un repository remoto con il nome *upstream*. Quando vogliamo sincronizzarci con il repository upstream (è meglio farlo spesso per non rimanere troppo indietro con gli aggiornamenti ) bisogna eseguire i seguenti comandi:

`git fetch upstream ( recupera una copia del repository remoto )`

`git rebase upstream/master ( applica le variazioni al repository locale )`

adesso è necessario aggiornare il proprio repository su Github  con il comando:

`git push origin master`

___

### :white_small_square: 6. Effettuare una pull request
Quando è stato fatto del lavoro di sviluppo su una parte del codice e si desidera che questa venga  incorporata nel progetto principale e necessario eseguire l'operazione di **pull request** dal proprio account Github verso il repository di cui abbiamo fatto il Fork all'inizio (il repository principale di progetto). La pull request sarà fatta dopo che tutti i file modificati sono stati sottoposti a commit locale ed il proprio repository remoto è stato aggiornato con un comando di *push* (vedi 4.b). Dopo una pull request questa deve essere approvata dal proprietario del repository di progetto. Attraverso l'ambiente di Github è possibile scambiare  commenti e chiarimenti tra gli sviluppatori prima che il proprietario del repository approvi o rifiuti la pull request.

