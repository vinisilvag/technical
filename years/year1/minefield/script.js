var vitoria;
var derrota;
var campo;
var campoLivre;
var lline, ccol;
var jogo;

function geraTabela(linha, coluna, bomb) {
	var zera = document.getElementById("tabela");
	zera.innerHTML = '';

	campoLivre = (linha*coluna)-bomb;
	campo = 1;
	
	jogo = new Array (linha);

	for (var i = 0; i < linha; i++) {
		jogo[i] = new Array (coluna);
		for (var j = 0; j < coluna; j++) {
			jogo[i][j] = 0;
		}
	}
}

function colocaBomba(linha, coluna, bomb) {
	var minas = 1;

	while (minas <= bomb) {
		var lin = Math.floor(Math.random()*linha);
		var col = Math.floor(Math.random()*coluna);
		if (jogo[lin][col] == 0) {
			jogo[lin][col] = -1;
			minas++;
		}
	}
}

function rodeiaBomba(linha, coluna, bomb) {
	var diferenca = Math.abs(linha-coluna);

	for(var i=0; i<linha; i++) {
		for(var j=0; j<coluna; j++) {
			if (jogo[i][j] == -1) {
				if (validaPosit(i, j+1) == 1) {
					jogo[i][j+1]++;
				}
				if (validaPosit(i, j-1) == 1) {
					jogo[i][j-1]++;
				}
				for(var k=0; k<3; k++) {
					if (validaPosit(i-1, j-1+k) == 1) {
						jogo[i-1][j-1+k]++;
					}
					if (validaPosit(i+1, j-1+k) == 1) {
						jogo[i+1][j-1+k]++;
					}
				}
			}
		}
	}
}

function printaTabela(linha, coluna) {
	for(var i=0; i<linha; i++) {
		for(var j=0; j<coluna; j++) {
			var cell = $("#tabela").append("<input type='button' id='"+i+":"+j+"' value='"+jogo[i][j]+"' class='open' onClick='cellEsquerdo(this)' onContextMenu='cellDireito(this)'></input>");
		}
	}
}

function cellEsquerdo(cell) {
	if (derrota == true || vitoria == true) {
		return false;
	}

	if (cell.className == "opened" || cell.className == "direito") {
		return false;
	}

	if (cell.value == -1) {
		cell.className = "bomba";
		derrota = true;
		alert("Você perdeu! Para jogar novamente selecione algum modo no menu!");
		mostraBomba();
	} else {
		cell.className = "opened";

		if (cell.value == 0) {
			cell.style.color = "transparent";
			var pegaid = cell.id;

			var line = parseInt(pegaid.substring(0, 2));
			var colum = parseInt(pegaid.substring(2, 5));
			if (isNaN(colum) == true) {
				colum = parseInt(pegaid.substring(3, 6));
			}
			liberaPerto(line, colum);
		} else {
			defineCor(cell);
		}
	}
	testaVitoria();
}

function cellDireito(cell) {
	document.addEventListener('contextmenu', event => event.preventDefault());

	if (derrota == true || vitoria == true) {
		return false;
	}
	
	if (cell.className == "opened") {
		return false;
	} else if (cell.className == "direito"){
		cell.className = "open";
	} else {
		cell.className = "direito";
	}
}

function mostraBomba() {
	for(var i=0; i<lline; i++) {
		for(var j=0; j<ccol; j++) {
			var cell = document.getElementById(i+":"+j);
			if (cell.value == -1) {
				cell.className = "bomba";
			} else {
				cell.className = "opened";
				defineCor(cell);
			}
		}
	}
}

function defineCor(cell) {
	if (cell.value == 0) 
		cell.style.color = "transparent";

	if (cell.value == 1) {
		cell.style.color = "#00C8FF";
		cell.style.borderColor = "#00C8FF";
	}

	if (cell.value == 2) {
		cell.style.color = "#19F200";
		cell.style.borderColor = "#19F200";
	}

	if (cell.value == 3) {
		cell.style.color = "#FF5B00";
		cell.style.borderColor = "#FF5B00";
	}

	if (cell.value == 4) {
		cell.style.color = "red";
		cell.style.borderColor = "red";
	}

	if (cell.value >= 5) {
		cell.style.color = "red";
		cell.style.borderColor = "red";
	}
}

function liberaPerto(lin, col) {
	for(var i=-1; i<=1; i++) {
		for(var j=-1; j<=1; j++) {
			var linha = lin+i;
			var coluna = col+j;
			var cell = document.getElementById(linha+":"+coluna);
			
			if (i != 0 || j != 0) {
				if (validaPosit(linha, coluna) == 1 && cell.className != "opened") {
					if (jogo[linha][coluna] == 0) {
						cell.className = "opened";
						defineCor(cell);
						liberaPerto(linha, coluna);
					} else {
						cell.className = "opened";
						defineCor(cell);
					}
				}
			}
		}
	}
}

function testaVitoria() {
	var k = 0

	for(var i=0; i<lline; i++) {
		for(var j=0; j<ccol; j++) {
			var cell = document.getElementById(i+":"+j);
			if (cell.className == "opened") {
				k++;
			}
		}
	}

	if (k === campoLivre && derrota != true) {
		vitoria = true;
		alert("Você ganhou! Parabéns! Caso queira jogar novamente selecione um modo no menu!");
	}
}

function validaPosit(lin, col) {
	if (jogo[lin] == undefined || jogo[lin][col] == undefined || jogo[lin][col] == -1) {
		return 0;
	} else {
		return 1;
	}
}

function defineTam(linha, coluna) {
	document.getElementById("tabela").style.width = ((linha*30)+(2*linha)) + "px";
	document.getElementById("tabela").style.height = ((30*coluna)+(2*coluna)) + "px";
}

function main(linha, coluna, bomb) {
	vitoria = false;
	derrota = false;
	lline = linha;
	ccol = coluna;

	defineTam(linha, coluna);

	geraTabela(linha, coluna, bomb);
	colocaBomba(linha, coluna, bomb);
	rodeiaBomba(linha, coluna, bomb);
	printaTabela(linha, coluna);
}

function maincustom() {
	var linha = document.getElementById('linhas').value;
	var coluna = document.getElementById('colunas').value;
	var bomb = document.getElementById('bombas').value;

	if (linha > 42 || coluna > 42) {
		alert("Dimensões muito grandes!");
		return false;
	}

	if (linha < 5 || coluna < 5) {
		alert("Dimensões muito pequenas!");
		return false;
	}

	if (bomb >= linha*coluna) {
		alert("Número de bombas excede o número de celulas!");
		return false;
	}

	if (bomb < 1) {
		alert("Número de bombas é muito pequeno!");
		return false;
	}
	
	defineTam(linha, coluna);

	vitoria = false;
	derrota = false;
	lline = coluna;
	ccol = linha;

	geraTabela(coluna, linha, bomb);
	colocaBomba(coluna, linha, bomb);
	rodeiaBomba(coluna, linha, bomb);
	printaTabela(coluna, linha);
}

window.onload = main(20, 20, 40);