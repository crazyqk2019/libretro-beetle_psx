#ifndef LIBRETRO_CORE_OPTIONS_INTL_H__
#define LIBRETRO_CORE_OPTIONS_INTL_H__

#if defined(_MSC_VER) && (_MSC_VER >= 1500 && _MSC_VER < 1900)
/* https://support.microsoft.com/en-us/kb/980263 */
#pragma execution_character_set("utf-8")
#pragma warning(disable:4566)
#endif

#include <libretro.h>

#include "libretro_options.h"

/*
 ********************************
 * VERSION: 1.3
 ********************************
 *
 * - 1.3: Move translations to libretro_core_options_intl.h
 *        - libretro_core_options_intl.h includes BOM and utf-8
 *          fix for MSVC 2010-2013
 *        - Added HAVE_NO_LANGEXTRA flag to disable translations
 *          on platforms/compilers without BOM support
 * - 1.2: Use core options v1 interface when
 *        RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION is >= 1
 *        (previously required RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION == 1)
 * - 1.1: Support generation of core options v0 retro_core_option_value
 *        arrays containing options with a single value
 * - 1.0: First commit
*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 ********************************
 * Core Option Definitions
 ********************************
*/

/* RETRO_LANGUAGE_JAPANESE */

/* RETRO_LANGUAGE_FRENCH */

/* RETRO_LANGUAGE_SPANISH */

/* RETRO_LANGUAGE_GERMAN */

/* RETRO_LANGUAGE_ITALIAN */

struct retro_core_option_definition option_defs_it[] = {
#if defined(HAVE_OPENGL) || defined(HAVE_OPENGLES) || defined(HAVE_VULKAN)
   {
      BEETLE_OPT(renderer),
      "Renderer (necessita riavvio)",
      "Seleziona il renderer video. Il renderer software è il più preciso ma ha requisiti di performance maggiori quando si utilizzano risoluzioni GPU interne più alte.  Il renderer hardware, seppure meno preciso, migliora le prestazioni rispetto al renderer software a risoluzioni interne maggiori e abilita vari miglioramenti grafici. 'Hardware' seleziona automaticamente il renderer Vulkan o OpenGL dipendendo dal driver video front-end di libretro attuale. Se il driver video fornito non è nè Vulkan nè OpenGL 3.3-compatibile allora verrà utilizzato il renderer software.",
      {
         { "hardware", "Hardware" },
         { "software", "Software" },
         { NULL, NULL },
      },
      "hardware"
   },
   {
      BEETLE_OPT(renderer_software_fb),
      "Framebuffer Software",
      "Abilita l'emulazione accurata di effetti framebuffer (es: motion blur, FF7 battle swirl) quando si utilizza renderer hardware usando una copia del renderer software a risoluzione nativa in sottofondo. Se disabilitato, le operazioni precedenti sono tralasciate (OpenGL) oppure renderizzate dalla GPU (Vulkan). Disabilitare questa impostazione può migliorare le performance ma potrebbe causare errori grafici gravi. In caso di incertezza lasciare 'Abilitato'.",
      {
         { "enabled",  NULL },
         { "disabled", NULL },
         { NULL, NULL },
      },
      "enabled"
   },
#endif
   {
      BEETLE_OPT(internal_resolution),
      "Risoluzione GPU Interna",
      "Imposta il moltiplicatore della risoluzione interna. Risoluzioni maggiori di '1x (Nativo)' migliorano la fedeltà dei modelli 3D a spese di requisiti di performance più alti. Elementi 2D sono generalmente non condizionati da questa impostazione.",
      {
         { "1x(native)", "1x (Nativo)" },
         { "2x",         NULL },
         { "4x",         NULL },
         { "8x",         NULL },
         { "16x",        NULL },
         { NULL, NULL },
      },
      "1x(native)"
   },
#if defined(HAVE_OPENGL) || defined(HAVE_OPENGLES)
   {
      BEETLE_OPT(depth),
      "Profondità Colori Interni",
      "Imposta la profondità dei colori interni. Una maggiore profondità dei colori può ridurre gli effetti di color banding senza l'uso di dithering. 16 bpp emula hardware originale ma potrebbe mostrare del color banding visibile se il dithering non è abilitato. E' consigliato disabilitare 'Dithering Pattern' quando questa impostazione è impostata su 32 bpp.",
      {
         { "16bpp(native)", "16 bpp (Nativo)" },
         { "32bpp",         "32 bpp" },
         { NULL, NULL },
      },
      "16bpp(native)"
   },
#endif
   {
      BEETLE_OPT(dither_mode),
      "Dithering Pattern",
      "Imposta la configurazione del pattern di dithering. '1x (Nativo)' emula il dithering di risoluzione nativa bassa utilizzato da hardware originale per ammorbidire gli artefatti di color banding visibili a profondità di colore nativi. 'Risoluzione Interna' scala la granularità di dithering alla risoluzione interna configurata per risultati più puliti. E' consigliato di disabilitare questa impostazione quando si utilizza la profondità di colore a 32 bpp. Nota: In Vulkan, abilitando questa opzione forzerà downsampling a profondità di colore native mentre disabilitandola abiliterà automaticamente output a profondità di colore maggiori.",
      {
         { "1x(native)",          "1x (Nativo)" },
         { "internal resolution", "Risoluzione Interna" },
         { "disabled",            NULL },
         { NULL, NULL },
      },
      "1x(native)"
   },
#if defined(HAVE_OPENGL) || defined(HAVE_OPENGLES) || defined(HAVE_VULKAN)
   {
      BEETLE_OPT(filter),
      "Texture Filtering",
      "Seleziona il metodo di texture filtering. 'Più vicino' emula l'hardware originale. 'Bilineare' e '3-Point' sono filtri di smoothing che riducono il pixellamento tramite sfocamento. 'SABR', 'xBR', e 'JINC2' sono filtri di upscaling che potrebbero migliorare la nitidezza delle texture a costo di requisiti di performance maggiori. Questa impostazione è supportata solo dai renderer hardware.",
      {
         { "nearest",  "Più vicino" },
         { "SABR",     NULL },
         { "xBR",      NULL },
         { "bilinear", "Bilineare" },
         { "3-point",  "3-Point" },
         { "JINC2",    NULL },
         { NULL, NULL },
      },
      "nearest"
   },
#endif
#ifdef HAVE_VULKAN
   {
      BEETLE_OPT(adaptive_smoothing),
      "Smoothing Addativo",
      "Se abilitato, ammorbidisce le immagini 2D e gli elementi UI senza sfocare oggetti renderizzati in 3D. Questa impostazione è supportata solo dal renderer Vulkan.",
      {
         { "enabled",  NULL },
         { "disabled", NULL },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      BEETLE_OPT(super_sampling),
      "Supersampling",
      "Se abilitato, sottocampiona l'immagine dalla risoluzione interna scalata alla risoluzione nativa. Combinando questa impostazione con multiplicatori di risoluzione interne maggiori permette ai giochi di essere visualizzati con oggetti 3D su cui vengono applicati l'antialiasing a risoluzione nativa minore. Produce risultati migliori quando viene applicato ai titoli che utilizzano elementi sia 2D che 3D (es: personaggi 3D su sfondi pre-rendered), e funziona bene in congiunzione con shader CRT. Questa impostazione è supportata solo dal renderer Vulkan. Nota: E' consigliato disabilitare 'Dithering Pattern' se si sta abilitando quest'impostazione.",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(msaa),
      "Multisample Anti-Aliasing (MSAA)",
      "Imposta il livello di MSAA. Migliora l'aspetto degli oggetti 3D. Questa impostazione è supportata solo dal renderer Vulkan.",
      {
         { "1x",  "1x (Predefinito)" },
         { "2x",  NULL },
         { "4x",  NULL },
         { "8x",  NULL },
         { "16x", NULL },
         { NULL, NULL },
      },
      "1x"
   },
   {
      BEETLE_OPT(mdec_yuv),
      "Filtro Chroma MDEC YUV Chroma",
      "Migliora la qualità del playback di FMV (full motion video) riducendo artifatti 'macroblocking' (margini quadrati/frastagliati). Questa impostazione è supportata solo dal renderer Vulkan.",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
#endif
#if defined(HAVE_OPENGL) || defined(HAVE_OPENGLES)
   {
      BEETLE_OPT(wireframe),
      "Modalità Wireframe (Debug)",
      "Se abilitato, vengono renderizzati soltanto solo gli spigoli, senza texture o shading, dei modelli 3D. Questa impostazione è supportata solo dal renderer hardware OpenGL. Nota: E' normalmente disabilitato siccome viene utilizzato solamente per scopi di debug.",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(display_vram),
      "Visualizza Full VRAM (Debug)",
      "Se abilitato, viene visualizzata la VRAM dell'intera console emulata. Questa impostazione è supportata solo dal renderer hardware OpenGL. Nota: E' normalmente disabilitato siccome viene utilizzato solamente per scopi di debug.",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
#endif
   {
      BEETLE_OPT(pgxp_mode),
      "Modalità Operazione PGXP",
      "Permette agli oggetti 3D di essere renderizzati con precisione sub-pixel, minimizzando effetti di distorsione e jittering di oggetti 3D visti su hardware originario a causa di uso di punti prefissati per le coordinate dei vertici. 'Solo Memoria', avendo problemi di compatibilità minimi, è consigliato per uso generale. 'Memoria + CPU (Buggy)' può ridurre il jittering ulteriormente ma ha requisiti di performance alti e può causare vari errori geometrici.",
      {
         { "disabled",     NULL },
         { "memory only",  "Solo Memoria" },
         { "memory + CPU", "Memoria + CPU (Buggy)" },
         { NULL, NULL },
      },
      "disabled"
   },
#if defined(HAVE_OPENGL) || defined(HAVE_OPENGLES) || defined(HAVE_VULKAN)
   {
      BEETLE_OPT(pgxp_vertex),
      "Vertice Cache PGXP",
      "Permette alle posizioni dei veritici migliorati da PGXP di essere memorizzati nella cache per riutilizzarli in poligoni. Può potenzialmente migliorare l'allineamento degli oggetti e ridurre cuciture visibili quando si renderizzano texture, potrebbe causare glitch grafici quando vengono trovati falsi positivi mentre si effettua il querying della cache. E' consigliato lasciare quest'opzione disabilitata per il momento. Questa impostazione è supportata solo dai renderer hardware ed è applicata solo quando la 'Modalità Operazione PGXP' è abilitata.",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(pgxp_texture),
      "Prospettiva Texturing Corretta PGXP",
      "Se abilitato, sostituisce il mapping affine nativo di PSX con il mapping prospettiva texturing corretta. Elimina distorzioni dipendenti dalla posizione e warping di texture, risultando in texture correttamente allineate. Questa impostazione è supportata solo dai renderer hardware e viene applicata solo quando 'Modalità Operazione PGXP' è abilitata.",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
#endif
   {
      BEETLE_OPT(display_internal_fps),
      "Visualizza Contatore FPS Interno",
      "Visualizza il contatore del frame rate interno a cui viene renderizzato il contenuto del sistema PlayStation emulato. Nota: Richiede di essere abilitato l'opzione delle notifiche su schermo in libretro.",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(line_render),
      "Line-to-Quad Hack",
      "Seleziona un metodo line-to-quad hack. Alcuni giochi (es: Doom, Hexen, Soul Blade, ecc.) disegnano linee orizzontali allungando triangoli alti un singolo pixel per tutto lo schermo, che vengono rasterizzati come una singola fila di pixel su hardware originali. Questa hack rileva questi piccoli triangoli e li converte a quadrati come necessitato, permettendo a loro di essere visualizzati appropriatamente sui renderer hardware e a una risoluzione interna maggiore. 'Aggressivo' è necessitato per certi titoli (es: Dark Forces, Duke Nukem) ma potrebbe altrimenti introdurre glitch grafichi. Imposta 'Predefinito' se incerti.",
      {
         { "default",    "Predefinito" },
         { "aggressive", "Aggressivo" },
         { "disabled",   NULL },
         { NULL, NULL },
      },
      "default"
   },
   {
      BEETLE_OPT(frame_duping),
      "Frame Duping (Speedup)",
      "Se abilitato e supportato dal front-end libretro, fornisce un minore aumento di performance indirizzando il front-end a ripetere il frame precedente se non risulta nulla di nuovo da visualizzare dal core.",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
#if defined(HAVE_LIGHTREC)
   {
      BEETLE_OPT(cpu_dynarec),
      "Ricompilazione Dinamica CPU (Dynarec)",
      "Ricompila dinamicamente le istruzioni di CPU a istruzioni native. Molto più veloce dell'interpreter, ma i timing della CPU sono meno accurati e potrebbero avere bug.",
      {
         { "disabled", "Disabilitato (Beetle Interpreter)" },
         { "execute",  "Performance Massima" },
         { "execute_one",  "Cycle Timing Check" },
         { "run_interpreter", "Lightrec Interpreter" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(dynarec_invalidate),
      "Invalidamento Codice Dynarec",
      "Alcuni giochi necessitano di invalidamenti 'Full', alcuni 'Solo DMA'.",
      {
         { "full", "Full" },
         { "dma",  "Solo DMA (Leggermente più Veloce)" },
         { NULL, NULL },
      },
      "full"
   },
   {
      BEETLE_OPT(dynarec_eventcycles),
      "Cicli Eventi Dynarec DMA/GPU",
      "Imposta quanti cicli possono passare nella CPU prima che un aggiornamento GPU o DMA è controllato. Un numero maggiore risulta in velocità maggiori, ma causa anche più probabilmente bug o crash. Questa impostazione ha molto meno impatto su beetle interpreter che su dynarec.",
      {
         { "128", "128 (Predefinito)" },
         { "256",  NULL },
         { "512",  NULL },
         { "1024",  NULL },
         { NULL, NULL },
      },
      "128"
   },
#endif
   {
      BEETLE_OPT(cpu_freq_scale),
      "Frequenza CPU (Overclock)",
      "Abilita overclock (o underclock) della CPU PSX emulata. L'overclock può eliminare rallentamenti e migliorare il frame rate in certi giochi a costo di requisiti di performance maggiori. Alcuni giochi non beneficiano del  overlock avendo un limitatore interno di frame rate. Potrebbe causare certi effetti di essere animati più velocemente del previsto in alcuni titoli quando si esegue l'overclock.",
      {
         { "100%(native)", "100% (Nativo)" },
         { NULL, NULL },
      },
      "100%(native)"
   },
   {
      BEETLE_OPT(gte_overclock),
      "Overclock GTE",
      "Se abilitato, riduce tutte le operazioni emulate GTE (co-processore CPU per grafiche 3D) ad una latenza di un ciclo costante. Per i giochi che fanno un utilizzo pesante di GTE, questa impostazione potrebbe migliorare enormemente il frame rate e la stabilità frame time.",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(gpu_overclock),
      "Overclock Rasterizzatore GPU",
      "Abilita l'overclock per il rasterizzatore 2D contenuto nella GPU del PSX emulato. Non migliora il rendering 3D e ha poco effetto in generale.",
      {
         { "1x(native)", "1x (Nativo)" },
         { "2x",         NULL },
         { "4x",         NULL },
         { "8x",         NULL },
         { "16x",        NULL },
         { "32x",        NULL },
         { NULL, NULL },
      },
      "1x(native)"
   },
   {
      BEETLE_OPT(skip_bios),
      "Salta BIOS",
      "Salta l'animazione di avvio BIOS PlayStation che viene visualizzata normalmente quando si carica del contenuto. Nota: Abilitato questa impostazione causa problemi di compatibilità con numerosi giochi (giochi con protezione da copia PAL, Saga Frontier, ecc.).",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(widescreen_hack),
      "Hack Modalità Widescreen",
      "Se abilitato, renderizza anamorficamente il contenuto 3D e invia in uscita il framebuffer emulato ad un rapporto d'aspetto widescreen. Produce risultati migliori con giochi interamente 3D. Elementi 2D verranno allargati orizzontalmente e potrebbero essere fuori posizione.",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(crop_overscan),
      "Taglia Overscan Orizzontale",
      "Da predefinito, i renderer aggiungono un'imbottitura orizzontale (colonne su entrambi i lati dell'immagine) per emulare le stesse barre nere generate in output video analogico da hardware PSX reali. Abilitando questa impostazione rimuove le imbottiture orizzontali.",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      BEETLE_OPT(image_crop),
      "Tagli Addizionali",
      "Se 'Taglia Overscan Orizzontale' è abilitato, quest'opzione riduce ulteriormente la larghezza dell'immagine tagliata di un numero specificato di pixel. Questa impostazione è supportata solo dai renderer software.",
      {
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(image_offset),
      "Offset Immagine Tagliata",
      "Se 'Taglia Overscan Orizzontale' è abilitato, quest'opzione permette all'immagine tagliata risultante di essere slittata orizzontalmente a destra (positivo) o sinistra (negativo) di un numero specificato di pixel. Può essere usato per risolvere problemi di allineamento. Questa impostazione è supportanta solo dai renderer software.",
      {
         { NULL, NULL },
      },
      "disabled"
   },
#if defined(HAVE_OPENGL) || defined(HAVE_OPENGLES) || defined(HAVE_VULKAN)
   {
      BEETLE_OPT(image_offset_cycles),
      "Offset Immagine Orizzontale (Cicli GPU)",
      "Specifica un numero di cicli GPU da slittare l'immagine. I valori positivi muovono l'immagine a destra, i valori negativi muovono invece l'immagine a sinistra. Questa impostazione è supportata solo dai renderer hardware.",
      {
         { NULL, NULL},
      },
      "0"
   },
#endif
   {
      BEETLE_OPT(initial_scanline),
      "Linea di Scansione Iniziale - NTSC",
      "Seleziona la prima linea di scansione visualizzata quando viene eseguito contenuto NTSC. Impostando un valore maggiore di 0 verrà ridotta l'altezza dell'immagine output tagliando pixel dal margine più in alto. Questa impostazione può essere utilizzata come contromisura per il letterboxing. Necessita riavvio per i renderer software.",
      {
         { NULL, NULL },
      },
      "0"
   },
   {
      BEETLE_OPT(last_scanline),
      "Linea di Scansione Finale - NTSC",
      "Seleziona l'ultima linea di scansione visualizzata quando viene eseguito contenuto NTSC. Impostando un valore minore di 239 verrà ridotta l'altezza dell'immagine output tagliando pixel dal margine più in basso. Questa impostazione può essere utilizzata come contromisura per il letterboxing. Necessita riavvio per i renderer software.",
      {
         { NULL, NULL },
      },
      "239"
   },
   {
      BEETLE_OPT(initial_scanline_pal),
      "Linea di Scansione Iniziale - PAL",
      "Seleziona la prima linea di scansione visualizzata quando viene eseguito contenuto PAL. Impostando un valore maggiore di 0 verrà ridotta l'altezza dell'immagine output tagliando pixel dal margine più in alto. Questa impostazione può essere utilizzata come contromisura per il letterboxing. Necessita riavvio per i renderer software.",
      {
         { NULL, NULL },
      },
      "0"
   },
   {
      BEETLE_OPT(last_scanline_pal),
      "Linea di Scansione Finale - PAL",
      "Seleziona l'ultima linea di scansione visualizzata quando viene eseguito contenuto PAL. Impostando un valore minore di 239 verrà ridotta l'altezza dell'immagine output tagliando pixel dal margine più in basso. Questa impostazione può essere utilizzata come contromisura per il letterboxing. Necessita riavvio per i renderer software.",
      {
         { NULL, NULL },
      },
      "287"
   },
#ifndef EMSCRIPTEN
   {
      BEETLE_OPT(cd_access_method),
      "Metodo Accesso CD (necessita riavvio)",
      "Seleziona il metodo utilizzato per leggere dati dai contenuti delle immagini disco. 'Sincrono' mimica l'hardware originale. 'Asincrono' può ridurre stuttering su dispositivi con storage lenti. 'Pre-Cache' carica l'intero disco immagine sulla memoria quando viene eseguito del contenuto, il che potrebbe migliorare tempi di caricamento in gioco a costo di un ritardo iniziale all'avvio. 'Pre-cache' potrebbe causare problemi su sistemi con poca RAM.",
      {
         { "sync",     "Sincrono" },
         { "async",    "Asincrono" },
         { "precache", "Pre-Cache" },
         { NULL, NULL },
      },
      "sync"
   },
#endif
   {
      BEETLE_OPT(cd_fastload),
      "Velocità Caricamento CD",
      "Seleziona il multiplicatore di velocità all'accesso del disco. Impostando questa opzione a maggiore di '2x (Nativo)' potrebbe ridurre enormemente i tempi di caricamento in gioco, ma potrebbe introdurre dei problemi di timing. Alcuni giochi potrebbero non funzionare appropriatamente se viene impostata sopra un certo valore.",
      {
         { "2x(native)", "2x (Nativo)" },
         { "4x",          NULL },
         { "6x",          NULL },
         { "8x",          NULL },
         { "10x",         NULL },
         { "12x",         NULL },
         { "14x",         NULL },
         { NULL, NULL },
      },
      "2x(native)"
   },
   {
      BEETLE_OPT(use_mednafen_memcard0_method),
      "Metodo Memory Card 0 (necessita riavvio)",
      "Seleziona il formato del salvataggio usato per la memory card 0. 'Libretro' è consigliato. 'Mednafen' può essere usato per compatibilità con la versione stand-alone di Mednafen.",
      {
         { "libretro", "Libretro" },
         { "mednafen", "Mednafen" },
         { NULL, NULL },
      },
      "libretro"
   },
   {
      BEETLE_OPT(enable_memcard1),
      "Abilita Memory Card 1",
      "Seleziona l'abilità di emulare la seconda memory card in slot 1. Se disabilitato i giochi possono solo accedere alla memory card in slot 0. Nota: Certi giochi richiedono questa impostazione di essere disabilitata (es: Codename Tenka).",
      {
         { "enabled",  NULL },
         { "disabled", NULL },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      BEETLE_OPT(shared_memory_cards),
      "Memory Cards Condivise (necessita riavvio)",
      "Se abilitato, tutti i giochi salveranno e caricheranno dagli stessi file memory card. Se disabilitato, file memory card separati saranno generati per ogni oggetto di contenuto caricato. Nota: L'opzione 'Metodo Memory Card 0' deve essere impostato su 'Mednafen' per il funzionamento corretto delle memory card condivise.",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(analog_calibration),
      "Auto-Calibrazione Analogici",
      "Se il dispositivo di input è impostato su DualShock, Controller Analogico, Joystick Analogico o neGcon, quest'opzione permette la calibrazione dinamica degli input analogici. I valori massimi di input registrati sono monitorati in tempo reale e sono usati per scalare le coordinate passate all'emulatore. Questa impostazione dovrebbe venir usata per giochi come Mega Man Legends 2 che richiedono valori maggiori di quelli che i controller moderni provvedono. Per risultati migliori gli stick analogici devono essere roteati alla massima capacità per mettere a punto l'algoritmo della calibrazione ogni volta che il contenuto viene caricato.",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(analog_toggle),
      "Abilita Modalità Toggle Dualshock Analogico",
      "Se il tipo di dispositivo input è DualShock, imposta l'abilità di DualShock emulato di essere cambiato da modalità DIGITALE a ANALOGICO e viceversa come nel hardware originale. Quando quest'opzione è disabilitata, DualShock è impostato su ANALOGICO, se abilitata invece, DualShock può essere alternata tra DIGITALE e ANALOGICO premendo e tenendo premuto START+SELECT+L1+L2+R1+R2.",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(enable_multitap_port1),
      "Porta 1: Abilita Multitap",
      "Abilita/Disabilita la funzionalità multitap sulla porta 1.",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(enable_multitap_port2),
      "Porta 2: Abilita Multitap",
      "Abilita/Disabilita la funzionalità multitap sulla porta 2.",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(gun_input_mode),
      "Modalità Input Pistola",
      "Specifica se utilizzare una 'Pistola Ottica' controllata dal mouse oppure un input 'Touchscreen' quando il tipo di dispositivo è impostato su 'Guncon / G-Con 45' o 'Justifier'.",
      {
         { "lightgun",    "Pistola Ottica" },
         { "touchscreen", "Touchscreen" },
         { NULL, NULL },
      },
      "lightgun"
   },
   {
      BEETLE_OPT(gun_cursor),
      "Cursore Pistola",
      "Seleziona il cursore della pistola che viene visualizzato su schermo quando vengono utilizzati i dispositivi input di tipo 'Guncon / G-Con 45' e 'Justifier'. Se disabilitato, i puntatori (cross hair) sono sempre nascosti.",
      {
         { "cross", "Croce" },
         { "dot",   "Puntino" },
         { "off",   "Disabilitato" },
         { NULL, NULL },
      },
      "cross"
   },
   {
      BEETLE_OPT(mouse_sensitivity),
      "Sensibilità Mouse",
      "Configura la sensibilità dei dispositivi input di tipo 'Mouse'.",
      {
         { NULL, NULL },
      },
      "100%"
   },
   {
      BEETLE_OPT(negcon_response),
      "Sensibilità Torsione negCon",
      "Specifica la sensibilità dello stick RetroPad analogico sinistro quando viene simulato la 'torsione' dei dispositivi input 'negCon' emulati. Lo dislocamento dello stick analogico può essere mappato all'angolo di rotazione del negCon in modo lineare, quadratico o cubico. 'Quadratico' permette una maggiore precisione rispetto a 'Lineare' mentre si eseguono movimenti minori. 'Cubico' incrementa ulteriormente la precisione di movimenti minori, ma 'esagera' movimenti maggiori. Nota: 'Lineare' è consigliato solo quando si utilizzano periferiche volante. I gamepad convenzionali implementano input analogici in una maniera fondamentalmente differente dal meccanismo di 'torsione' del neGcon: la loro mappatura lineare sovramplificano movimenti minori, compromettendo i controlli raffinati. Nella maggior parte dei casi 'Quadratico' provvede l'approssimazione più vicina a hardware reali.",
      {
         { "linear",    "Lineare" },
         { "quadratic", "Quadratico" },
         { "cubic",     "Cubico" },
         { NULL, NULL },
      },
      "linear"
   },
   {
      BEETLE_OPT(negcon_deadzone),
      "Zona Morta Torsione negCon",
      "Imposta la zona morta (deadzone) dello stick RetroPad analogico sinistro quando viene simulato l'azione 'torsione' dei dispositivi input 'negCon' emulati. Utilizzato per eliminare drift dei controller. Nota: La maggior parte dei titoli compatibili con negCon provvedono opzioni in gioco per impostare il valore di zona morta della 'torsione'. Per evitare perdite di precisione, la zona morta in gioco dovrebbe essere quasi sempre impostata su 0. Qualunque aggiustamento necessario dovrebbe essere *solo* impostata tramite questa impostazione ed è particolarmente importante quando 'Sensibilità Torsione negCon' è impostata su 'Quadratico' o 'Cubico'.",
      {
         { NULL, NULL },
      },
      "0%"
   },
   { NULL, NULL, NULL, {{0}}, NULL },
};

/* RETRO_LANGUAGE_DUTCH */

/* RETRO_LANGUAGE_PORTUGUESE_BRAZIL */

/* RETRO_LANGUAGE_PORTUGUESE_PORTUGAL */

/* RETRO_LANGUAGE_RUSSIAN */

/* RETRO_LANGUAGE_KOREAN */

/* RETRO_LANGUAGE_CHINESE_TRADITIONAL */

/* RETRO_LANGUAGE_CHINESE_SIMPLIFIED */

struct retro_core_option_definition option_defs_chs[] = {
#if defined(HAVE_OPENGL) || defined(HAVE_OPENGLES) || defined(HAVE_VULKAN)
   {
      BEETLE_OPT(renderer),
      "渲染器（须要重启）",
      "选择视频渲染器\n"
      "软件渲染器最精确，但是随着内部GPU分辨率提高，对机器性能的要求增长非常快。\n"
      "硬件渲染器精度略低，但是在高分辨率下能够提供更佳的性能，并且可以实现各种特效。\n"
      "'硬件（自动）'根据当前libretro前端的视频驱动自动选择Vulkan或者OpenGL渲染器，\n"
      "如果当前视频驱动不是Vulkan或者OpenGL 3.3兼容驱动，则自动使用软件渲染器。",
      {
         { "hardware",    "硬件 (自动)" },
#if defined(HAVE_OPENGL) || defined(HAVE_OPENGLES)
         { "hardware_gl", "硬件 (OpenGL)" },
#endif
#if defined(HAVE_VULKAN)
         { "hardware_vk", "硬件 (Vulkan)" },
#endif
         { "software",    "软件" },
         { NULL, NULL },
      },
      "hardware"
   },
   {
      BEETLE_OPT(renderer_software_fb),
      "软件帧缓存",
      "使用硬件渲染器时，通过在后台以原始分辨率运行一个软件渲染器拷贝的方式，\n"
      "实现精确模拟帧缓存特效（例如动作模糊，FF7战斗场景旋转）。\n"
      "如果禁用此项，这些特效在OpenGL模式下会被忽略，在Vulkan模式下则交由GPU渲染。\n"
      "禁用此项可以提高性能，但是会引起图像错误。如果不确信如何选择，请保持启用。",
      {
         { "enabled",  NULL },
         { "disabled", NULL },
         { NULL, NULL },
      },
      "enabled"
   },
#endif
   {
      BEETLE_OPT(internal_resolution),
      "内部GPU分辨率",
      "设置内部分辨率倍数。\n"
      "高于'1x (原始)'的分辨率可以提高3D模型精度，但对机器性能的要求也会提高。\n"
      "2D元素通常不受此项影响。",
      {
         { "1x(native)", "1x (原始)" },
         { "2x",         NULL },
         { "4x",         NULL },
         { "8x",         NULL },
         { "16x",        NULL },
         { NULL, NULL },
      },
      "1x(native)"
   },
#if defined(HAVE_OPENGL) || defined(HAVE_OPENGLES)
   {
      BEETLE_OPT(depth),
      "内部色彩位深",
      "设置内部色彩位深。\n"
      "高色深可以不使用抖动就可以减少色彩条块效应。\n"
      "16位色深模拟原始硬件，但是不使用抖动时会有可见的色彩条块。\n"
      "设为32位色深时，建议禁用'抖动模式'。",
      {
         { "16bpp(native)", "16位（原始）" },
         { "32bpp",         "32位" },
         { NULL, NULL },
      },
      "16bpp(native)"
   },
   // Sort of, it's more like 15-bit high color and 24-bit true color for visible output. The alpha channel is used for mask bit. Vulkan renderer uses ABGR1555_555 for 31 bits internal? FMVs are always 24-bit on all renderers like original hardware (BGR888, no alpha)
#endif
   {
      BEETLE_OPT(dither_mode),
      "抖动模式",
      "设置抖动模式。\n"
      "'1x（原始）'模拟原始硬件的低分辨率抖动，平滑原始色深下的色块效果。\n"
      "'内部分辨率'放大抖动粒度到设置的内部分辨率以达到更好的效果。\n"
      "设为32位色深时，建议禁用此项。\n"
      "注意：在Vulkan模式下，启用此项会强制降低为原始色深，而禁用时会自动启用高色深输出。",
      {
         { "1x(native)",          "1x（原始）" },
         { "internal resolution", "内部分辨率" },
         { "disabled",            NULL },
         { NULL, NULL },
      },
      "1x(native)"
   },
#if defined(HAVE_OPENGL) || defined(HAVE_OPENGLES) || defined(HAVE_VULKAN)
   {
      BEETLE_OPT(filter),
      "纹理过滤",
      "选择纹理过滤算法。\n"
      "'最临近'模拟原始硬件。\n"
      "'双线性' 和 '3点取样'是平滑滤镜，通过模糊效果平滑像素边缘。\n"
      "'SABR', 'xBR', 和 'JINC2'是放大滤镜，可以提高纹理精度/锐度，\n"
      "但是需要更高的机器性能。只支持硬件渲染器。",
      {
         { "nearest",  "最临近" },
         { "SABR",     NULL },
         { "xBR",      NULL },
         { "bilinear", "双线性" },
         { "3-point",  "3点取样" },
         { "JINC2",    NULL },
         { NULL, NULL },
      },
      "nearest"
   },
#endif
#ifdef HAVE_VULKAN
   {
      BEETLE_OPT(adaptive_smoothing),
      "自适应平滑",
      "平滑2D图像和UI元素，而不引起3D对象模糊。\n"
      "只支持Vulkan渲染器。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(super_sampling),
      "超采样",
      "把渲染内容从内部高分辨率缩小到原始分辨率输出，\n"
      "结合高内部分辨率倍数使用，可以实现在原始低分辨率下的3D对象反锯齿功能。\n"
      "此功能对于混合2D和3D元素的图块有最佳的效果（例如3D角色显示在2D背景上），\n"
      "和CRT渲染器也能很好的结合工作。\n"
      "只支持Vulkan渲染器。\n"
      "注意：启用此项时建议禁用'抖动模式'。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(msaa),
      "多重采样抗锯齿",
      "设置MSAA级别，增强3D对象显示效果。只支持Vulkan渲染器。",
      {
         { "1x",  "1x（缺省）" },
         { "2x",  NULL },
         { "4x",  NULL },
         { "8x",  NULL },
         { "16x", NULL },
         { NULL, NULL },
      },
      "1x"
   },
   {
      BEETLE_OPT(mdec_yuv),
      "MDEC YUV色度滤镜",
      "提高FMV动画回放质量，减少马赛克效果。\n"
      "只支持Vulkan渲染器。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(track_textures),
      "跟踪纹理",
      "纹理导出和替换的前提条件。在大多数游戏里可能会引起崩溃。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
#ifdef TEXTURE_DUMPING_ENABLED
   {
      BEETLE_OPT(dump_textures),
      "纹理导出",
      "导出使用的纹理材质到<cd>-texture-dump/目录",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
#endif
   {
      BEETLE_OPT(replace_textures),
      "纹理替换",
      "用<cd>-texture-replacements/目录下的高清纹理材质替换游戏内纹理材质。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },   
#endif
#if defined(HAVE_OPENGL) || defined(HAVE_OPENGLES)
   {
      BEETLE_OPT(wireframe),
      "线条框架模式（调试）",
      "只渲染3D模型的轮廓，不渲染纹理和着色。\n"
      "只支持OpenGL硬件渲染器。\n"
      "注意：此项用于调试目的，通常应该禁用。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
#endif
#if defined(HAVE_OPENGL) || defined(HAVE_OPENGLES) || defined(HAVE_VULKAN)
   {
      BEETLE_OPT(display_vram),
      "显示全部VRAM（调试）",
      "显示整个模拟VRAM内容。\n"
      "只支持OpenGL和Vulkan硬件渲染器。\n"
      "注意：此项用于调试目的，通常应该禁用。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
#endif
   {
      BEETLE_OPT(pgxp_mode),
      "PGXP操作模式",
      "允许以子像素精度渲染3D对象，最小化原始硬件上由于使用整数顶点坐标而产生的3D对象的变形和抖动。\n"
      "'仅内存'模式兼容性问题最小，建议通常情况下使用。\n"
      "'内存+CPU（有Bug）'模式可以进一步减少抖动，\n"
      "但是对机器的性能要求更高，并且可能产生各种几何错误。",
      {
         { "disabled",     NULL },
         { "memory only",  "仅内存" },
         { "memory + CPU", "内存 + CPU（有Bug）" },
         { NULL, NULL },
      },
      "disabled"
   },
#if defined(HAVE_OPENGL) || defined(HAVE_OPENGLES) || defined(HAVE_VULKAN)
   {
      BEETLE_OPT(pgxp_vertex),
      "PGXP顶点缓存",
      "允许缓存PGXP增强型顶点位置，以在绘制多个多边形时重用。\n"
      "可以潜在地改善3D对象对齐，减少可见的贴图缝隙，\n"
      "但是缓存查询失败可能产生图像问题。\n"
      "当前建议禁用此项。\n"
      "此项只在PGXP操作模式启用时有效。只支持硬件渲染器。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(pgxp_texture),
      "PGXP纹理透视校正",
      "用透视校正纹理映射替换PSX原始的仿射纹理映射，\n"
      "消除位置相关的纹理变形和扭曲，产生正确对齐的纹理。\n"
      "此项只在PGXP操作模式启用时有效。只支持硬件渲染器。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
#endif
   {
      BEETLE_OPT(display_internal_fps),
      "显示内部FPS",
      "显示模拟PlayStation系统当前渲染内容的内部帧率。\n"
      "注意：需要在libretro前端中打开屏幕消息显示（OSD）。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(line_render),
      "Line-to-Quad修正",
      "选择line-to-quad修正模式。\n"
      "有些游戏（例如 Doom, Hexen, Soul Blade等）通过在屏幕上拉长单像素高度的三角形的方式来绘制水平线条，\n"
      "在原始硬件上这些三角形会光栅化为单排像素。\n"
      "此修正检测这些小的三角形并根据需要转换成四边形，以使它们在使用硬件渲染器和高内部分辨率时能正确显示。\n"
      "'激进'模式对有些游戏是必须的（例如 Dark Forces, Duke Nukem），但是对其他游戏可能产生图像问题。\n"
      "如果不确信如何选择，保持'缺省'模式。",
      {
         { "default",    "缺省" },
         { "aggressive", "激进" },
         { "disabled",   NULL },
         { NULL, NULL },
      },
      "default"
   },
   {
      BEETLE_OPT(frame_duping),
      "帧欺骗（提速）",
      "当启用并且libretro前端支持时，可以提供较小的性能提升，\n"
      "实现方式是当内核没有显示内容更新时，指示前端重复显示前一帧。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
#if defined(HAVE_LIGHTREC)
   {
      BEETLE_OPT(cpu_dynarec),
      "CPU动态重编译",
      "动态重编译CPU指令为本机指令。\n"
      "比解释器快很多，但是CPU时序精度较低，并且可能有bug。",
      {
         { "disabled", "禁用（Beetle解释器）" },
         { "execute",  "最高性能" },
         { "execute_one",  "周期时序检测" },
         { "run_interpreter", "轻量重编译解释器" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(dynarec_invalidate),
      "动态重编译代码失效方式",
      "有些游戏需要完全失效，有些需要仅DMA。",
      {
         { "full", "完全" },
         { "dma",  "仅DMA（略快一点）" },
         { NULL, NULL },
      },
      "full"
   },
   {
      BEETLE_OPT(dynarec_eventcycles),
      "动态重编译DMA/GPU事件时钟周期",
      "每次检查GPU或DMA更新前，CPU运行的最大时钟周期数。\n"
      "值越高速度越快。对于解释器的影响要比对动态重编译小很多。",
      {
         { "128", "128 (Default)" },
         { "256",  NULL },
         { "384",  NULL },
         { "512",  NULL },
         { "640",  NULL },
         { "768",  NULL },
         { "896",  NULL },
         { "1024",  NULL },
         { NULL, NULL },
      },
      "128"
   },
#endif
   {
      BEETLE_OPT(cpu_freq_scale),
      "CPU频率调节（超频）",
      "启用对模拟PSX CPU的超频或降频。\n"
      "超频可以减少特定游戏的拖慢，提高帧率，但是对机器性能要求更高。\n"
      "注意：有些游戏有内部帧率限制，无法从超频获益。\n"
      "超频时可能会使有些游戏的某些动画特效比设计值运行的更快。",
      {
         { "50%",           NULL },
         { "60%",           NULL },
         { "70%",           NULL },
         { "80%",           NULL },
         { "90%",           NULL },
         { "100%(native)", "100%（原始）" },
         { "110%",          NULL },
         { "120%",          NULL },
         { "130%",          NULL },
         { "140%",          NULL },
         { "150%",          NULL },
         { "160%",          NULL },
         { "170%",          NULL },
         { "180%",          NULL },
         { "190%",          NULL },
         { "200%",          NULL },
         { "210%",          NULL },
         { "220%",          NULL },
         { "230%",          NULL },
         { "240%",          NULL },
         { "250%",          NULL },
         { "260%",          NULL },
         { "270%",          NULL },
         { "280%",          NULL },
         { "290%",          NULL },
         { "300%",          NULL },
         { "310%",          NULL },
         { "320%",          NULL },
         { "330%",          NULL },
         { "340%",          NULL },
         { "350%",          NULL },
         { "360%",          NULL },
         { "370%",          NULL },
         { "380%",          NULL },
         { "390%",          NULL },
         { "400%",          NULL },
         { "410%",          NULL },
         { "420%",          NULL },
         { "430%",          NULL },
         { "440%",          NULL },
         { "450%",          NULL },
         { "460%",          NULL },
         { "470%",          NULL },
         { "480%",          NULL },
         { "490%",          NULL },
         { "500%",          NULL },
         { "510%",          NULL },
         { "520%",          NULL },
         { "530%",          NULL },
         { "540%",          NULL },
         { "550%",          NULL },
         { "560%",          NULL },
         { "570%",          NULL },
         { "580%",          NULL },
         { "590%",          NULL },
         { "600%",          NULL },
         { "610%",          NULL },
         { "620%",          NULL },
         { "630%",          NULL },
         { "640%",          NULL },
         { "650%",          NULL },
         { "660%",          NULL },
         { "670%",          NULL },
         { "680%",          NULL },
         { "690%",          NULL },
         { "700%",          NULL },
         { "710%",          NULL },
         { "720%",          NULL },
         { "730%",          NULL },
         { "740%",          NULL },
         { "750%",          NULL },
         { NULL, NULL },
      },
      "100%(native)"
   },
   {
      BEETLE_OPT(gte_overclock),
      "GTE超频",
      "启用时，降低所有模拟GTE（CPU的3D图形协处理）操作的延迟为固定的一个时钟周期。\n"
      "对于有些重度使用GTE的游戏，此项可以大幅提高帧率和帧时间稳定性。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(gpu_overclock),
      "GPU光栅化器超频",
      "启用对模拟的PSX GPU内包含的2D光栅化器的超频。\n"
      "不会提升3D渲染，并且通常只有很小的效果。",
      {
         { "1x(native)", "1x（原始）" },
         { "2x",         NULL },
         { "4x",         NULL },
         { "8x",         NULL },
         { "16x",        NULL },
         { "32x",        NULL },
         { NULL, NULL },
      },
      "1x(native)"
   },
   {
      BEETLE_OPT(skip_bios),
      "跳过BIOS",
      "跳过启动时的PlayStation BIOS启动动画。\n"
      "注意：对于个别游戏启用此项可能导致兼容性问题（PAL制版权保护游戏，浪漫沙迦 等）。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(core_timing_fps),
      "内核报告的FPS时序",
      "设置内核报告给前端的FPS时序。\n"
      "'自动切换'允许内核在报告逐行和隔行帧率之间切换，但是可能导致前端音视频驱动重初始化。",
      {
         { "force_progressive", "逐行帧率（缺省）" },
         { "force_interlaced",  "强制隔行帧率" },
         { "auto_toggle", "自动切换" },
      },
      "force_progressive"
   },
   {
      BEETLE_OPT(aspect_ratio),
      "内核画面宽高比",
      "设置内核输出画面宽高比。\n"
      "此项设置在启用宽屏修改或显示全部VRAM内容时被忽略。",
      {
         { "corrected", "纠正的" },
         { "uncorrected", "未纠正的" },
         { "4:3",  "强制4:3" },
         { "ntsc", "强制NTSC" },
      },
      "corrected"
   },
   {
      BEETLE_OPT(widescreen_hack),
      "宽屏修改",
      "启用时，变形渲染3D内容，然后以宽屏宽高比输出到模拟帧缓存。\n"
      "对于全3D游戏可以产生最佳效果。2D元素会被水平拉长，并且可能不对齐。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(pal_video_timing_override),
      "PAL（欧洲）制视频时序覆盖",
      "由于标准不同，PAL制游戏通常会比其美国或日本NTSC制版本运行速度慢。\n"
      "此项设置可以覆盖PAL制的时序，以使这些游戏以NTSC帧率运行。\n"
      "此项设置对于NTSC游戏无效。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(crop_overscan),
      "剪切水平过扫描",
      "缺省情况下，渲染器会在图像两边添加水平填充，以模拟真实PSX硬件模拟视频输出的黑边。\n"
      "启用此项移除水平填充。",
      {
         { "enabled",  NULL },
         { "disabled", NULL },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      BEETLE_OPT(image_crop),
      "额外剪切",
      "当'剪切水平过扫描'启用时，此项可以指定额外剪切的像素个数以进一步减小图像宽度。\n"
      "只支持软件渲染器。",
      {
         { "disabled", NULL },
         { "1px",      NULL },
         { "2px",      NULL },
         { "3px",      NULL },
         { "4px",      NULL },
         { "5px",      NULL },
         { "6px",      NULL },
         { "7px",      NULL },
         { "8px",      NULL },
         { "9px",      NULL },
         { "10px",     NULL },
         { "11px",     NULL },
         { "12px",     NULL },
         { "13px",     NULL },
         { "14px",     NULL },
         { "15px",     NULL },
         { "16px",     NULL },
         { "17px",     NULL },
         { "18px",     NULL },
         { "19px",     NULL },
         { "20px",     NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(image_offset),
      "剪切图像偏移量",
      "当'剪切水平过扫描'启用时，对剪切后的图像进行指定像素单位的水平位移，向右（正值）或者向左（负值），\n"
      "可以用来解决对齐问题。\n"
      "只支持软件渲染器。",
      {
         { "-12px",    NULL },
         { "-11px",    NULL },
         { "-10px",    NULL },
         { "-9px",     NULL },
         { "-8px",     NULL },
         { "-7px",     NULL },
         { "-6px",     NULL },
         { "-5px",     NULL },
         { "-4px",     NULL },
         { "-3px",     NULL },
         { "-2px",     NULL },
         { "-1px",     NULL },
         { "disabled", NULL },
         { "+1px",     NULL },
         { "+2px",     NULL },
         { "+3px",     NULL },
         { "+4px",     NULL },
         { "+5px",     NULL },
         { "+6px",     NULL },
         { "+7px",     NULL },
         { "+8px",     NULL },
         { "+9px",     NULL },
         { "+10px",    NULL },
         { "+11px",    NULL },
         { "+12px",    NULL },
         { NULL, NULL },
      },
      "disabled"
   },
#if defined(HAVE_OPENGL) || defined(HAVE_OPENGLES) || defined(HAVE_VULKAN)
   {
      BEETLE_OPT(image_offset_cycles),
      "水平图像偏移（GPU周期）",
      "指定以GPU时钟周期为单位的图像偏移量。\n"
      "正值向右偏移，负值向左偏移。\n"
      "只支持硬件渲染器。",
      {
         { "-40",      NULL },
         { "-39",      NULL },
         { "-38",      NULL },
         { "-37",      NULL },
         { "-36",      NULL },
         { "-35",      NULL },
         { "-34",      NULL },
         { "-33",      NULL },
         { "-32",      NULL },
         { "-31",      NULL },
         { "-30",      NULL },
         { "-29",      NULL },
         { "-28",      NULL },
         { "-27",      NULL },
         { "-26",      NULL },
         { "-25",      NULL },
         { "-24",      NULL },
         { "-23",      NULL },
         { "-22",      NULL },
         { "-21",      NULL },
         { "-20",      NULL },
         { "-19",      NULL },
         { "-18",      NULL },
         { "-17",      NULL },
         { "-16",      NULL },
         { "-15",      NULL },
         { "-14",      NULL },
         { "-13",      NULL },
         { "-12",      NULL },
         { "-11",      NULL },
         { "-10",      NULL },
         { "-9",       NULL },
         { "-8",       NULL },
         { "-7",       NULL },
         { "-6",       NULL },
         { "-5",       NULL },
         { "-4",       NULL },
         { "-3",       NULL },
         { "-2",       NULL },
         { "-1",       NULL },
         { "0",        NULL },
         { "+1",       NULL },
         { "+2",       NULL },
         { "+3",       NULL },
         { "+4",       NULL },
         { "+5",       NULL },
         { "+6",       NULL },
         { "+7",       NULL },
         { "+8",       NULL },
         { "+9",       NULL },
         { "+10",      NULL },
         { "+11",      NULL },
         { "+12",      NULL },
         { "+13",      NULL },
         { "+14",      NULL },
         { "+15",      NULL },
         { "+16",      NULL },
         { "+17",      NULL },
         { "+18",      NULL },
         { "+19",      NULL },
         { "+20",      NULL },
         { "+21",      NULL },
         { "+22",      NULL },
         { "+23",      NULL },
         { "+24",      NULL },
         { "+25",      NULL },
         { "+26",      NULL },
         { "+27",      NULL },
         { "+28",      NULL },
         { "+29",      NULL },
         { "+30",      NULL },
         { "+31",      NULL },
         { "+32",      NULL },
         { "+33",      NULL },
         { "+34",      NULL },
         { "+35",      NULL },
         { "+36",      NULL },
         { "+37",      NULL },
         { "+38",      NULL },
         { "+39",      NULL },
         { "+40",      NULL },
         { NULL, NULL},
      },
      "0"
   },
#endif
   {
      BEETLE_OPT(initial_scanline),
      "起始扫描线 - NTSC",
      "选择运行NTSC制游戏时第一条显示的扫描线。\n"
      "设置大于0的值会剪切掉顶部的像素从而减小输出图像的高度。\n"
      "可用来抵消边框效果。",
      {
         { "0",  NULL },
         { "1",  NULL },
         { "2",  NULL },
         { "3",  NULL },
         { "4",  NULL },
         { "5",  NULL },
         { "6",  NULL },
         { "7",  NULL },
         { "8",  NULL },
         { "9",  NULL },
         { "10", NULL },
         { "11", NULL },
         { "12", NULL },
         { "13", NULL },
         { "14", NULL },
         { "15", NULL },
         { "16", NULL },
         { "17", NULL },
         { "18", NULL },
         { "19", NULL },
         { "20", NULL },
         { "21", NULL },
         { "22", NULL },
         { "23", NULL },
         { "24", NULL },
         { "25", NULL },
         { "26", NULL },
         { "27", NULL },
         { "28", NULL },
         { "29", NULL },
         { "30", NULL },
         { "31", NULL },
         { "32", NULL },
         { "33", NULL },
         { "34", NULL },
         { "35", NULL },
         { "36", NULL },
         { "37", NULL },
         { "38", NULL },
         { "39", NULL },
         { "40", NULL },
         { NULL, NULL },
      },
      "0"
   },
   {
      BEETLE_OPT(last_scanline),
      "结束扫描线 - NTSC",
      "选择运行NTSC制游戏时最后一条显示的扫描线。\n"
      "设置小于239的值会剪切掉底部的像素从而减小输出图像的高度。\n"
      "可用来抵消边框效果。",
      {
         { "210", NULL },
         { "211", NULL },
         { "212", NULL },
         { "213", NULL },
         { "214", NULL },
         { "215", NULL },
         { "216", NULL },
         { "217", NULL },
         { "218", NULL },
         { "219", NULL },
         { "220", NULL },
         { "221", NULL },
         { "222", NULL },
         { "223", NULL },
         { "224", NULL },
         { "225", NULL },
         { "226", NULL },
         { "227", NULL },
         { "228", NULL },
         { "229", NULL },
         { "230", NULL },
         { "231", NULL },
         { "232", NULL },
         { "233", NULL },
         { "234", NULL },
         { "235", NULL },
         { "236", NULL },
         { "237", NULL },
         { "238", NULL },
         { "239", NULL },
         { NULL, NULL },
      },
      "239"
   },
   {
      BEETLE_OPT(initial_scanline_pal),
      "起始扫描线 - PAL",
      "选择运行PAL制游戏时第一条显示的扫描线。\n"
      "设置大于0的值会剪切掉顶部的像素从而减小输出图像的高度。\n"
      "可用来抵消边框效果。",
      {
         { "0",  NULL },
         { "1",  NULL },
         { "2",  NULL },
         { "3",  NULL },
         { "4",  NULL },
         { "5",  NULL },
         { "6",  NULL },
         { "7",  NULL },
         { "8",  NULL },
         { "9",  NULL },
         { "10", NULL },
         { "11", NULL },
         { "12", NULL },
         { "13", NULL },
         { "14", NULL },
         { "15", NULL },
         { "16", NULL },
         { "17", NULL },
         { "18", NULL },
         { "19", NULL },
         { "20", NULL },
         { "21", NULL },
         { "22", NULL },
         { "23", NULL },
         { "24", NULL },
         { "25", NULL },
         { "26", NULL },
         { "27", NULL },
         { "28", NULL },
         { "29", NULL },
         { "30", NULL },
         { "31", NULL },
         { "32", NULL },
         { "33", NULL },
         { "34", NULL },
         { "35", NULL },
         { "36", NULL },
         { "37", NULL },
         { "38", NULL },
         { "39", NULL },
         { "40", NULL },
         { NULL, NULL },
      },
      "0"
   },
   {
      BEETLE_OPT(last_scanline_pal),
      "结束扫描线 - PAL",
      "选择运行PAL制游戏时最后一条显示的扫描线。\n"
      "设置小于287的值会剪切掉底部的像素从而减小输出图像的高度。\n"
      "可用来抵消边框效果。",
      {
         { "230", NULL },
         { "231", NULL },
         { "232", NULL },
         { "233", NULL },
         { "234", NULL },
         { "235", NULL },
         { "236", NULL },
         { "237", NULL },
         { "238", NULL },
         { "239", NULL },
         { "240", NULL },
         { "241", NULL },
         { "242", NULL },
         { "243", NULL },
         { "244", NULL },
         { "245", NULL },
         { "246", NULL },
         { "247", NULL },
         { "248", NULL },
         { "249", NULL },
         { "250", NULL },
         { "251", NULL },
         { "252", NULL },
         { "253", NULL },
         { "254", NULL },
         { "255", NULL },
         { "256", NULL },
         { "257", NULL },
         { "258", NULL },
         { "259", NULL },
         { "260", NULL },
         { "261", NULL },
         { "262", NULL },
         { "263", NULL },
         { "264", NULL },
         { "265", NULL },
         { "266", NULL },
         { "267", NULL },
         { "268", NULL },
         { "269", NULL },
         { "270", NULL },
         { "271", NULL },
         { "272", NULL },
         { "273", NULL },
         { "274", NULL },
         { "275", NULL },
         { "276", NULL },
         { "277", NULL },
         { "278", NULL },
         { "279", NULL },
         { "280", NULL },
         { "281", NULL },
         { "282", NULL },
         { "283", NULL },
         { "284", NULL },
         { "285", NULL },
         { "286", NULL },
         { "287", NULL },
         { NULL, NULL },
      },
      "287"
   },
#ifndef EMSCRIPTEN
   {
      BEETLE_OPT(cd_access_method),
      "CD访问方式（须重启）",
      "选择从游戏光盘镜像读取数据的方式。\n"
      "'同步'模拟原始硬件。'异步'可以减少慢速存储设备的卡顿。\n"
      "'预缓存'在游戏启动时读取整个光盘镜像到内存，可以提高游戏中的加载速度，\n"
      "但是会增加启动时的延迟，并且在低内存系统上可能会产生问题。",
      {
         { "sync",     "同步" },
         { "async",    "异步" },
         { "precache", "预缓存" },
         { NULL, NULL },
      },
      "sync"
   },
#endif
   {
      BEETLE_OPT(cd_fastload),
      "CD载入速度",
      "选择光驱倍速。\n"
      "设置大于'2x（原始）'可以极大的缩短游戏载入时间，但是可能导致时序错误。\n"
      "有些游戏在大于一定值时可能无法正常工作。",
      {
         { "2x(native)", "2x（原始）" },
         { "4x",          NULL },
         { "6x",          NULL },
         { "8x",          NULL },
         { "10x",         NULL },
         { "12x",         NULL },
         { "14x",         NULL },
         { NULL, NULL },
      },
      "2x(native)"
   },
   {
      BEETLE_OPT(use_mednafen_memcard0_method),
      "记忆卡0格式（须重启）",
      "选择记忆卡0的数据格式。\n"
      "'Mednafen'可用于保持与独立版本Mednafen的兼容性。\n"
      "用于Beetle PSX内核时，Libretro (.srm) 和 Mednafen (.mcr) 格式内部是相同的，可以通过重命名直接转换。",
      {
         { "libretro", "Libretro" },
         { "mednafen", "Mednafen" },
         { NULL, NULL },
      },
      "libretro"
   },
   {
      BEETLE_OPT(enable_memcard1),
      "启用记忆卡1（须重启）",
      "选择是否模拟插槽1中的第二块记忆卡。\n"
      "如果禁用，游戏只能访问插槽0中的第一块记忆卡。\n"
      "注意：有些游戏须要禁用此项才能正确运行（例如 Codename Tenka）。\n"
      "记忆卡1使用Mednafen (.mcr) 保存格式。",
      {
         { "enabled",  NULL },
         { "disabled", NULL },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      BEETLE_OPT(shared_memory_cards),
      "共享记忆卡（须重启）",
      "如果启用，所有游戏共享同一个记忆卡文件。如果禁用，每个游戏使用单独的记忆卡文件。\n"
      "注意：'记忆卡0格式'必须设为'Mednafen'才能使用共享记忆卡。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(analog_calibration),
      "模拟摇杆自校正",
      "当输入设备设为双震动手柄、模拟控制器、模拟摇杆或者neGcon时，\n"
      "此选项可以允许动态校正模拟输入。\n"
      "最大输入值会被动态实时监测，用于缩放传输给模拟器的坐标范围。\n"
      "某些游戏例如 Mega Man Legends 2 需要打开此项，他们需要比现今控制器能提供的更大的输入值。\n"
      "为获得最佳效果，每次游戏载入时应全范围旋转模拟摇杆一圈，以优化校准算法。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(analog_toggle),
      "启用双震动手柄模拟模式切换",
      "当输入设备是双震动手柄时，设置是否模拟双震动手柄的数字和模拟模式切换功能。\n"
      "如果设为禁用，双震动手柄锁定为模拟模式；\n"
      "如果设为启用，双震动手柄可以通过同时按住'开始+选择+L1+L2+R1+R2'切换模拟和数字模式。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(enable_multitap_port1),
      "端口 1: 启用分插器",
      "启用/禁用端口1上的手柄分插器功能。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(enable_multitap_port2),
      "端口 2: 启用分插器",
      "启用/禁用端口2上的手柄分插器功能。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      BEETLE_OPT(gun_input_mode),
      "光枪输入模式",
      "当输入设备类型设为'Guncon / G-Con 45' 或者 'Justifier'时，指定是使用鼠标模拟的'光枪'还是'触摸屏'输入。",
      {
         { "lightgun",    "光枪" },
         { "touchscreen", "触摸屏" },
         { NULL, NULL },
      },
      "lightgun"
   },
   // Shouldn't the gun_input_mode just be Mouse vs. Touchscreen?
   {
      BEETLE_OPT(gun_cursor),
      "光枪准心",
      "使用'Guncon / G-Con 45' 或者 'Justifier'输入设备时，选择显示的光枪准心。\n"
      "如果禁用，准心总是隐藏。",
      {
         { "cross", "十字" },
         { "dot",   "点" },
         { "off",   "disabled" },
         { NULL, NULL },
      },
      "cross"
   },
   {
      BEETLE_OPT(mouse_sensitivity),
      "鼠标灵敏度",
      "设置鼠标输入设备的灵敏度。",
      {
         { "5%",   NULL },
         { "10%",  NULL },
         { "15%",  NULL },
         { "20%",  NULL },
         { "25%",  NULL },
         { "30%",  NULL },
         { "35%",  NULL },
         { "40%",  NULL },
         { "45%",  NULL },
         { "50%",  NULL },
         { "55%",  NULL },
         { "60%",  NULL },
         { "65%",  NULL },
         { "70%",  NULL },
         { "75%",  NULL },
         { "80%",  NULL },
         { "85%",  NULL },
         { "90%",  NULL },
         { "95%",  NULL },
         { "100%", NULL },
         { "105%", NULL },
         { "110%", NULL },
         { "115%", NULL },
         { "120%", NULL },
         { "125%", NULL },
         { "130%", NULL },
         { "135%", NULL },
         { "140%", NULL },
         { "145%", NULL },
         { "150%", NULL },
         { "155%", NULL },
         { "160%", NULL },
         { "165%", NULL },
         { "170%", NULL },
         { "175%", NULL },
         { "180%", NULL },
         { "185%", NULL },
         { "190%", NULL },
         { "195%", NULL },
         { "200%", NULL },
         { NULL, NULL },
      },
      "100%"
   },
   {
      BEETLE_OPT(negcon_response),
      "NegCon 扭转响应",
      "指定左模拟摇杆模拟'neGcon'输入设备的'扭转'功能时的响应方式。\n"
      "模拟摇杆位移量可以通过线性，二次方，三次方算法映射为negCon的旋转角度。\n"
      "进行小的移动时，'二次方'比'线性'提供更高的精度。\n"
      "'三次方'精度更高，但是会'夸大'较大的移动。\n"
      "注意：'线性'只推荐使用赛车方向盘周边时使用。\n"
      "传统手柄实现模拟输入的方式和 neGcon '扭转'的机制基本原理不同，\n"
      "因此线性映射过度放大小的移动，会损害控制体验。\n"
      "大多数情况下，'二次方'提供和真实硬件最为接近的体验。",
      {
         { "linear",    "线性" },
         { "quadratic", "二次方" },
         { "cubic",     "三次方" },
         { NULL, NULL },
      },
      "linear"
   },
   {
      BEETLE_OPT(negcon_deadzone),
      "NegCon 扭转盲区",
      "设置左模拟摇杆模拟'neGcon'输入设备的'扭转'功能时的盲区，用于消除摇杆漂移。\n"
      "注意：大多数 negCon 兼容游戏提供游戏内的选项以设置'扭转'盲区值。\n"
      "为避免损失精度，游戏内的盲区设置应该永远设为0，\n"
      "所有调节都应通过此选项设置，特别是当'NegCon 扭转响应'设为'二次方'或'立方'时尤其重要。",
      {
         { "0%",  NULL },
         { "5%",  NULL },
         { "10%", NULL },
         { "15%", NULL },
         { "20%", NULL },
         { "25%", NULL },
         { "30%", NULL },
         { NULL, NULL },
      },
      "0%"
   },
   {
      BEETLE_OPT(memcard_left_index),
      "左边记忆卡索引",
      "更改当前加载到左边插槽的记忆卡。该选项只有当记忆卡0设为Mednafen时有效。缺省记忆卡索引是0。",
      {
         { "0",  NULL },
         { "1",  NULL },
         { "2",  NULL },
         { "3",  NULL },
         { "4",  NULL },
         { "5",  NULL },
         { "6",  NULL },
         { "7",  NULL },
         { "8",  NULL },
         { "9",  NULL },
         { "10",  NULL },
         { "11",  NULL },
         { "12",  NULL },
         { "13",  NULL },
         { "14",  NULL },
         { "15",  NULL },
         { "16",  NULL },
         { "17",  NULL },
         { "18",  NULL },
         { "19",  NULL },
         { "20",  NULL },
         { "21",  NULL },
         { "22",  NULL },
         { "23",  NULL },
         { "24",  NULL },
         { "25",  NULL },
         { "26",  NULL },
         { "27",  NULL },
         { "28",  NULL },
         { "29",  NULL },
         { "30",  NULL },
         { "31",  NULL },
         { "32",  NULL },
         { "33",  NULL },
         { "34",  NULL },
         { "35",  NULL },
         { "36",  NULL },
         { "37",  NULL },
         { "38",  NULL },
         { "39",  NULL },
         { "40",  NULL },
         { "41",  NULL },
         { "42",  NULL },
         { "43",  NULL },
         { "44",  NULL },
         { "45",  NULL },
         { "46",  NULL },
         { "47",  NULL },
         { "48",  NULL },
         { "49",  NULL },
         { "50",  NULL },
         { "51",  NULL },
         { "52",  NULL },
         { "53",  NULL },
         { "54",  NULL },
         { "55",  NULL },
         { "56",  NULL },
         { "57",  NULL },
         { "58",  NULL },
         { "59",  NULL },
         { "60",  NULL },
         { "61",  NULL },
         { "62",  NULL },
         { "63",  NULL },
         { NULL, NULL },
      },
      "0"
   },
   {
      BEETLE_OPT(memcard_right_index),
      "右边记忆卡索引",
      "更改当前加载到右边插槽的记忆卡。该选项只有当记忆卡1启用时有效。缺省记忆卡索引是1。",
      {
         { "0",  NULL },
         { "1",  NULL },
         { "2",  NULL },
         { "3",  NULL },
         { "4",  NULL },
         { "5",  NULL },
         { "6",  NULL },
         { "7",  NULL },
         { "8",  NULL },
         { "9",  NULL },
         { "10",  NULL },
         { "11",  NULL },
         { "12",  NULL },
         { "13",  NULL },
         { "14",  NULL },
         { "15",  NULL },
         { "16",  NULL },
         { "17",  NULL },
         { "18",  NULL },
         { "19",  NULL },
         { "20",  NULL },
         { "21",  NULL },
         { "22",  NULL },
         { "23",  NULL },
         { "24",  NULL },
         { "25",  NULL },
         { "26",  NULL },
         { "27",  NULL },
         { "28",  NULL },
         { "29",  NULL },
         { "30",  NULL },
         { "31",  NULL },
         { "32",  NULL },
         { "33",  NULL },
         { "34",  NULL },
         { "35",  NULL },
         { "36",  NULL },
         { "37",  NULL },
         { "38",  NULL },
         { "39",  NULL },
         { "40",  NULL },
         { "41",  NULL },
         { "42",  NULL },
         { "43",  NULL },
         { "44",  NULL },
         { "45",  NULL },
         { "46",  NULL },
         { "47",  NULL },
         { "48",  NULL },
         { "49",  NULL },
         { "50",  NULL },
         { "51",  NULL },
         { "52",  NULL },
         { "53",  NULL },
         { "54",  NULL },
         { "55",  NULL },
         { "56",  NULL },
         { "57",  NULL },
         { "58",  NULL },
         { "59",  NULL },
         { "60",  NULL },
         { "61",  NULL },
         { "62",  NULL },
         { "63",  NULL },
         { NULL, NULL },
      },
      "1"
   },   
   { NULL, NULL, NULL, {{0}}, NULL },
};

/* RETRO_LANGUAGE_ESPERANTO */

/* RETRO_LANGUAGE_POLISH */

/* RETRO_LANGUAGE_VIETNAMESE */

/* RETRO_LANGUAGE_ARABIC */

/* RETRO_LANGUAGE_GREEK */

/* RETRO_LANGUAGE_TURKISH */

#ifdef __cplusplus
}
#endif

#endif
