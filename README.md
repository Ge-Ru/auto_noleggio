Si considerino i dati di un'agenzia di autonoleggio contenuti nel file "auto.csv"; tale file contiene le informazioni sulle auto appartenenti al parco macchine dell'agenzia e in ogni riga è riportato:

 Categoria, Marca, Modello, Colore, L/A, L/A,L/A, L/A, L/A, L/A, L/A 
 Si facciano le seguenti assunzioni: 
il campo categoria può assumere i valori: "utilitaria", "media”, "lusso", "sportiva" e "furgone";
il numero di righe del file non è noto a priori e non si deve assumere nessun particolare ordinamento;
il file "auto cv' è formattato correttamente; 
non ci sono auto identiche;
i valori L/A indicano se la macchina è già stata affittata (A) o è libera (L) per il giorno della settimana corrispondente. 
Il programma deve gestire le prenotazioni per una settimana da lunedì a domenica, nell'ipotesi che una macchina possa essere affittata solo per giornate intere e non spezzoni di giornata. Le giornate sono specificate indicando tutti i giorni per cui si intende prenotare l'auto codificati come 1=lunedì, 2=martedì…, 7=domenica 

Scrivere un programma C++che permetta all'utente di inserire la categoria di macchina e i giorni in cui intende affittare l'auto (separati tra loro da spazio); il programma restituisce tutte le auto, se esistono, che soddisfano la richiesta dell'utente. II programma deve stampare il messaggio "Auto non disponibile" se non esistono auto che soddisfano le specifiche dell'utente. Se esistono auto disponibili l'utente deve poter scegliere un veicolo e il programma stampare a video l'elenco aggiornato di tutte le prenotazioni.

Si richiede:

Casi d'uso (opzionale)
Programma in C++
File di testo contenente il link della repository pubblica github su cui è caricato il programma e attraverso il quale si evince lo storico dei commit 
Esempio 

(dato il file "auto.csv" come quello allegato al presente compito)

Categoria, Marca, Modello, Colore, Lunedì, Martedì, Mercoledì, Giovedì, Venerdì, Sabato, Domenica
utilitaria, FIAT, Panda, rosso, L, L, L, A, A, A, A
utilitaria, KIA, Pikanto, bronzo, A, A, L, L, L, A, A 
lusso, Mercedes, Classe 5, nero, L, L, L, L, L, A, A 
sportiva, Lamborghini, Huracan, giallo, L, L, L, L, L, L, L
furgone, Ford, Transit, bianco, A, A, A, A, A, L, L
lusso, BMW, Serie 5, grigio metallizzato, L, L, L, L, L, A, A 
utilitaria, Peugeot, 108, verde, L, A, L, L, L, A, L
Scegli categoria e giorni: utilitaria 3 4

Le macchine disponibili sono:

  KIA Pikanto colore bronzo
  Peugeot 108 colore verde
Quale vuoi prenotare? 1

(A video verrà stampato il nuovo file auto.csv aggiornato con la macchina presa in affitto secondo le giornate.)

Categoria, Marca, Modello, Colore, Lunedì, Martedì, Mercoledì, Giovedì, Venerdì, Sabato, Domenica
utilitaria, FIAT, Panda, rosso, L, L, L, A, A, A, A
utilitaria, KIA, Pikanto, bronzo, A, A, A, A, L, A, A 
lusso, Mercedes, Classe 5, nero, L, L, L, L, L, A, A 
sportiva, Lamborghini, Huracan, giallo, L, L, L, L, L, L, L
furgone, Ford, Transit, bianco, A, A, A, A, A, L, L
lusso, BMW, Serie 5, grigio metallizzato, L, L, L, L, L, A, A 
utilitaria, Peugeot, 108, verde, L, A, L, L, L, A, L
