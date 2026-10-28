# ProjetoFinal_PI-CIN0005

Trabalho Final da cadeira Programação Imperativa - 2º Período

## Instruções de stup

Primeiramente, para quem usa Windows, é recomendável que se tenha o WSL instalado. Sério, deem uma chance para o Linux no seu Windows, sei que muita gente não gosta dele, mas, uma vez que você aprende, é mágico demais! Usar o Linux facilita bastante a vida do programador; como o próprio Linus Torvalds disse: _"Se a Microsoft faz aplicações para Linux, significa que eu ganhei."_

Dito isto, deixo aqui um [tutorial](https://github.com/DianneK13/ProjetoFinal_PI-CIN0005/blob/main/Tutorial/WSL.md) de como instalá-lo em sua máquina :)

---

### 1o - Clone o repositório

Dentro do WSL, rode:

```bash
git clone https://github.com/DianneK13/ProjetoFinal_PI-CIN0005 --recursive
```

### 2o - Compile o raylib

```bash
cd ProjetoFinal_PI-CIN0005/external/raylib/src
make
```

### 3o - Compile o projeto

Volte para a pasta do projeto e digite o comando

```bash
cd ProjetoFinal_PI-CIN0005
make
```

### 4o - Rode o projeto

```bash
./main
```

---

## Organização dos assets

```
assets/
├── audio/
│   ├── music/            # músicas de fundo (menu e gameplay)
│   └── sfx/              # efeitos sonoros
└── images/
    ├── menu/             # fundo do menu, fundo dos créditos e botões
    ├── gameplay/         # fundo do quarto
    │   └── objetos/      # camadas dos objetos clicáveis do quarto
    ├── zoom/             # uma pasta por cena de zoom (caixaArmario, caixaCama, bilhete, ...)
    ├── falas/            # caixas de diálogo
    ├── ending/           # tela de finalização
    ├── ui/               # elementos de interface (botão de voltar, ícones de som)
    └── personagens/      # artes dos personagens
```

- Use nomes de arquivo sem acento nem espaço (evita problemas entre Linux, WSL e macOS).
- O jogo desenha tudo em 1200x800; imagens novas que ocupam a tela inteira devem ser exportadas nesse tamanho.

---

## Contribuidores

<a href="https://github.com/DianneK13/ProjetoFinal_PI-CIN0005/graphs/contributors">
  <img src="https://contributors-img.web.app/image?repo=DianneK13/ProjetoFinal_PI-CIN0005&max=500" &columns=20&anon=1" />
</a>
