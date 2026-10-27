#include "sfx.h"

// caminho de cada som, na mesma ordem do enum SfxId
static const char *sfxPaths[SFX_COUNT] = {
    [SFX_BOTAO]   = "assets/audio/sfx/botao.mp3",
    [SFX_GARRAFA] = "assets/audio/sfx/garrafa.mp3",
    [SFX_LIVRO]   = "assets/audio/sfx/livro.mp3",
    [SFX_INICIO]  = "assets/audio/sfx/inicio_macaco.wav",
    [SFX_BAU]     = "assets/audio/sfx/bau.mp3",
    [SFX_PUZZLE]  = "assets/audio/sfx/finalizarpuzzle.mp3",
    [SFX_DIALOGO] = "assets/audio/sfx/dialogo.wav",
};

static Sound sounds[SFX_COUNT];
static bool loaded = false;

// Precisa ser chamado depois de InitAudioDevice
void LoadSFX(void) {
    if (loaded) return;
    for (int i = 0; i < SFX_COUNT; i++) {
        sounds[i] = LoadSound(sfxPaths[i]);
    }
    loaded = true;
}

void PlaySFX(SfxId id) {
    if (!loaded || id < 0 || id >= SFX_COUNT) return;
    if (IsSoundValid(sounds[id])) PlaySound(sounds[id]);
}

// Precisa ser chamado antes de CloseAudioDevice
void UnloadSFX(void) {
    if (!loaded) return;
    for (int i = 0; i < SFX_COUNT; i++) {
        UnloadSound(sounds[i]);
    }
    loaded = false;
}
