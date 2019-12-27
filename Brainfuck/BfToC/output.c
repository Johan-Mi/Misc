#include <stdlib.h>
#include <stdio.h>

int main(void) {
	unsigned short ptr = 0;
	unsigned char memory[65536] = {0};

	memory[ptr] += 13;
	while(memory[ptr]) {
		memory[ptr]--;
		ptr++;
		memory[ptr] += 2;
		ptr += 3;
		memory[ptr] += 5;
		ptr++;
		memory[ptr] += 2;
		ptr++;
		memory[ptr]++;
		ptr -= 6;
	}
	ptr += 5;
	memory[ptr] += 6;
	ptr++;
	memory[ptr] -= 3;
	ptr += 10;
	memory[ptr] += 15;
	while(memory[ptr]) {
		while(memory[ptr]) {
			ptr += 9;
		}
		memory[ptr]++;
		while(memory[ptr]) {
			ptr -= 9;
		}
		ptr += 9;
		memory[ptr]--;
	}
	memory[ptr]++;
	while(memory[ptr]) {
		ptr += 8;
		while(memory[ptr]) {
			memory[ptr]--;
		}
		ptr++;
	}
	ptr -= 9;
	while(memory[ptr]) {
		ptr -= 9;
	}
	ptr += 8;
	while(memory[ptr]) {
		memory[ptr]--;
	}
	memory[ptr]++;
	ptr -= 7;
	memory[ptr] += 5;
	while(memory[ptr]) {
		memory[ptr]--;
		while(memory[ptr]) {
			memory[ptr]--;
			ptr += 9;
			memory[ptr]++;
			ptr -= 9;
		}
		ptr += 9;
	}
	ptr += 7;
	memory[ptr]++;
	ptr += 27;
	memory[ptr]++;
	ptr -= 17;
	while(memory[ptr]) {
		ptr -= 9;
	}
	ptr += 3;
	while(memory[ptr]) {
		memory[ptr]--;
	}
	memory[ptr]++;
	while(memory[ptr]) {
		ptr += 6;
		while(memory[ptr]) {
			ptr += 7;
			while(memory[ptr]) {
				memory[ptr]--;
			}
			ptr += 2;
		}
		ptr -= 9;
		while(memory[ptr]) {
			ptr -= 9;
		}
		ptr += 7;
		while(memory[ptr]) {
			memory[ptr]--;
		}
		memory[ptr]++;
		ptr -= 6;
		memory[ptr] += 4;
		while(memory[ptr]) {
			memory[ptr]--;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr += 9;
				memory[ptr]++;
				ptr -= 9;
			}
			ptr += 9;
		}
		ptr += 6;
		memory[ptr]++;
		ptr -= 6;
		memory[ptr] += 7;
		while(memory[ptr]) {
			memory[ptr]--;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr += 9;
				memory[ptr]++;
				ptr -= 9;
			}
			ptr += 9;
		}
		ptr += 6;
		memory[ptr]++;
		ptr -= 16;
		while(memory[ptr]) {
			ptr -= 9;
		}
		ptr += 3;
		while(memory[ptr]) {
			while(memory[ptr]) {
				memory[ptr]--;
			}
			ptr += 6;
			while(memory[ptr]) {
				ptr += 7;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 6;
					memory[ptr]++;
					ptr += 6;
				}
				ptr -= 6;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 6;
					memory[ptr]++;
					ptr -= 2;
					memory[ptr]++;
					ptr -= 3;
					memory[ptr]++;
					ptr--;
				}
				ptr += 8;
			}
			ptr -= 9;
			while(memory[ptr]) {
				ptr -= 9;
			}
			ptr += 9;
			while(memory[ptr]) {
				ptr += 8;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 7;
					memory[ptr]++;
					ptr += 7;
				}
				ptr -= 7;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 7;
					memory[ptr]++;
					ptr -= 2;
					memory[ptr]++;
					ptr -= 3;
					memory[ptr]++;
					ptr -= 2;
				}
				ptr += 8;
			}
			ptr -= 9;
			while(memory[ptr]) {
				ptr -= 9;
			}
			ptr += 7;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr -= 7;
				memory[ptr]++;
				ptr += 7;
			}
			ptr -= 7;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr += 7;
				memory[ptr]++;
				ptr -= 2;
				memory[ptr]++;
				ptr -= 5;
			}
			ptr += 9;
			memory[ptr] += 15;
			while(memory[ptr]) {
				while(memory[ptr]) {
					ptr += 9;
				}
				memory[ptr]++;
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				memory[ptr]--;
			}
			memory[ptr]++;
			while(memory[ptr]) {
				ptr++;
				memory[ptr]++;
				ptr += 8;
			}
			ptr -= 9;
			while(memory[ptr]) {
				ptr -= 9;
			}
			ptr += 9;
			while(memory[ptr]) {
				ptr++;
				memory[ptr]--;
				ptr += 4;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 4;
					memory[ptr]++;
					ptr += 4;
				}
				ptr -= 4;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 4;
					memory[ptr]++;
					ptr -= 5;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 2;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr -= 2;
							memory[ptr]++;
							ptr += 2;
						}
						ptr -= 2;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 2;
							memory[ptr]++;
							ptr += 2;
							memory[ptr]++;
							ptr -= 4;
						}
						memory[ptr]++;
						ptr += 9;
					}
					ptr -= 8;
					while(memory[ptr]) {
						ptr -= 9;
					}
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr += 9;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 9;
						memory[ptr]++;
						ptr -= 9;
					}
					ptr -= 10;
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 9;
					memory[ptr]++;
					ptr -= 9;
				}
				ptr--;
				memory[ptr]++;
				ptr += 8;
			}
			ptr -= 9;
			while(memory[ptr]) {
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr--;
				memory[ptr]--;
				ptr += 4;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 4;
					memory[ptr]++;
					ptr++;
					while(memory[ptr]) {
						ptr--;
						memory[ptr]--;
						ptr++;
						memory[ptr]--;
						ptr -= 6;
						memory[ptr]++;
						ptr += 6;
					}
					ptr--;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr++;
						memory[ptr]++;
						ptr--;
					}
					ptr += 4;
				}
				ptr -= 3;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 3;
					memory[ptr]++;
					ptr -= 3;
				}
				ptr--;
				memory[ptr]++;
				ptr -= 9;
			}
			ptr += 9;
			while(memory[ptr]) {
				ptr++;
				memory[ptr]++;
				ptr += 8;
			}
			ptr -= 9;
			while(memory[ptr]) {
				ptr -= 9;
			}
			ptr += 9;
			while(memory[ptr]) {
				ptr++;
				memory[ptr]--;
				ptr += 5;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 5;
					memory[ptr]++;
					ptr += 5;
				}
				ptr -= 5;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 5;
					memory[ptr]++;
					ptr -= 6;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 3;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr -= 3;
							memory[ptr]++;
							ptr += 3;
						}
						ptr -= 3;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 3;
							memory[ptr]++;
							ptr++;
							memory[ptr]++;
							ptr -= 4;
						}
						memory[ptr]++;
						ptr += 9;
					}
					ptr -= 8;
					while(memory[ptr]) {
						ptr -= 9;
					}
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr += 9;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr += 2;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 9;
						memory[ptr]++;
						ptr -= 9;
					}
					ptr -= 11;
				}
				ptr += 2;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 9;
					memory[ptr]++;
					ptr -= 9;
				}
				ptr -= 2;
				memory[ptr]++;
				ptr += 8;
			}
			ptr -= 9;
			while(memory[ptr]) {
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr--;
				memory[ptr]--;
				ptr += 4;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 4;
					memory[ptr]++;
					ptr++;
					while(memory[ptr]) {
						ptr--;
						memory[ptr]--;
						ptr++;
						memory[ptr]--;
						ptr -= 6;
						memory[ptr]++;
						ptr += 6;
					}
					ptr--;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr++;
						memory[ptr]++;
						ptr--;
					}
					ptr += 4;
				}
				ptr -= 3;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 3;
					memory[ptr]++;
					ptr -= 3;
				}
				ptr--;
				memory[ptr]++;
				ptr -= 9;
			}
			ptr += 9;
			while(memory[ptr]) {
				ptr += 4;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 36;
					memory[ptr]++;
					ptr += 36;
				}
				ptr += 5;
			}
			ptr -= 9;
			while(memory[ptr]) {
				ptr -= 9;
			}
			ptr += 9;
			memory[ptr] += 15;
			while(memory[ptr]) {
				while(memory[ptr]) {
					ptr += 9;
				}
				ptr -= 9;
				memory[ptr]--;
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				memory[ptr]--;
			}
			memory[ptr]++;
			ptr += 21;
			memory[ptr]++;
			ptr -= 3;
			while(memory[ptr]) {
				ptr -= 9;
			}
			ptr += 9;
			while(memory[ptr]) {
				ptr += 3;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 3;
					memory[ptr]--;
					ptr += 3;
				}
				memory[ptr]++;
				ptr -= 3;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 3;
					memory[ptr]--;
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 4;
						memory[ptr]++;
						ptr += 4;
					}
					ptr -= 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 4;
						memory[ptr]++;
						ptr -= 13;
						while(memory[ptr]) {
							ptr -= 9;
						}
						ptr += 4;
						while(memory[ptr]) {
							memory[ptr]--;
						}
						memory[ptr]++;
						ptr += 5;
						while(memory[ptr]) {
							ptr += 9;
						}
						ptr++;
						memory[ptr]++;
						ptr--;
					}
				}
				memory[ptr]++;
				ptr += 4;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 4;
					memory[ptr]--;
					ptr += 4;
				}
				memory[ptr]++;
				ptr -= 4;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 4;
					memory[ptr]--;
					ptr--;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 3;
						memory[ptr]++;
						ptr += 3;
					}
					ptr -= 3;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 3;
						memory[ptr]++;
						ptr -= 12;
						while(memory[ptr]) {
							ptr -= 9;
						}
						ptr += 3;
						while(memory[ptr]) {
							memory[ptr]--;
						}
						memory[ptr]++;
						ptr += 6;
						while(memory[ptr]) {
							ptr += 9;
						}
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
						}
						memory[ptr]++;
						ptr--;
					}
				}
				memory[ptr]++;
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr--;
					while(memory[ptr]) {
						ptr += 9;
					}
					ptr -= 8;
				}
				ptr += 8;
			}
			ptr -= 9;
			while(memory[ptr]) {
				ptr -= 9;
			}
			ptr -= 7;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr++;
				memory[ptr]++;
				ptr += 3;
				memory[ptr]--;
				ptr -= 4;
			}
			ptr += 9;
			memory[ptr] += 26;
			ptr += 2;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr -= 4;
				memory[ptr]++;
				ptr += 4;
			}
			ptr -= 4;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr += 4;
				memory[ptr]++;
				ptr -= 2;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr -= 2;
			}
			ptr += 2;
			while(memory[ptr]) {
				ptr -= 7;
				memory[ptr]++;
				ptr--;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr--;
					memory[ptr]++;
					ptr += 4;
					memory[ptr]++;
					ptr -= 2;
					while(memory[ptr]) {
						memory[ptr]--;
					}
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 2;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr++;
						memory[ptr]++;
						ptr += 3;
						memory[ptr]--;
						ptr -= 4;
					}
					ptr += 3;
				}
				ptr += 13;
				while(memory[ptr]) {
					ptr += 2;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr += 5;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 3;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr += 6;
				while(memory[ptr]) {
					ptr += 5;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 4;
						memory[ptr]++;
						ptr += 4;
					}
					ptr -= 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 4;
						memory[ptr]++;
						ptr -= 3;
						memory[ptr]++;
						ptr--;
					}
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr += 2;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 9;
						memory[ptr]++;
						ptr += 9;
					}
					ptr += 7;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				memory[ptr] += 15;
				while(memory[ptr]) {
					while(memory[ptr]) {
						ptr += 9;
					}
					memory[ptr]++;
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr -= 9;
					while(memory[ptr]) {
						ptr -= 9;
					}
					ptr += 9;
					memory[ptr]--;
				}
				memory[ptr]++;
				while(memory[ptr]) {
					ptr++;
					memory[ptr]++;
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr++;
					memory[ptr]--;
					ptr += 5;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 5;
						memory[ptr]++;
						ptr += 5;
					}
					ptr -= 5;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 5;
						memory[ptr]++;
						ptr -= 6;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr -= 2;
								memory[ptr]++;
								ptr += 2;
							}
							ptr -= 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 2;
								memory[ptr]++;
								ptr++;
								memory[ptr]++;
								ptr -= 3;
							}
							memory[ptr]++;
							ptr += 9;
						}
						ptr -= 8;
						while(memory[ptr]) {
							ptr -= 9;
						}
					}
					ptr += 9;
					while(memory[ptr]) {
						ptr += 9;
					}
					ptr -= 9;
					while(memory[ptr]) {
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 9;
							memory[ptr]++;
							ptr -= 9;
						}
						ptr -= 10;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 9;
						memory[ptr]++;
						ptr -= 9;
					}
					ptr--;
					memory[ptr]++;
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr--;
					memory[ptr]--;
					ptr += 3;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 3;
						memory[ptr]++;
						ptr++;
						while(memory[ptr]) {
							ptr--;
							memory[ptr]--;
							ptr++;
							memory[ptr]--;
							ptr -= 7;
							memory[ptr]++;
							ptr += 7;
						}
						ptr--;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
							ptr--;
						}
						ptr += 3;
					}
					ptr -= 2;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 2;
						memory[ptr]++;
						ptr -= 2;
					}
					ptr--;
					memory[ptr]++;
					ptr -= 9;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr += 6;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 5;
						memory[ptr]++;
						ptr += 5;
					}
					ptr -= 5;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 5;
						memory[ptr]++;
						ptr -= 4;
						memory[ptr]++;
						ptr--;
					}
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr++;
					memory[ptr]++;
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr++;
					memory[ptr]--;
					ptr += 5;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 5;
						memory[ptr]++;
						ptr += 5;
					}
					ptr -= 5;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 5;
						memory[ptr]++;
						ptr -= 6;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr -= 2;
								memory[ptr]++;
								ptr += 2;
							}
							ptr -= 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 2;
								memory[ptr]++;
								ptr += 2;
								memory[ptr]++;
								ptr -= 4;
							}
							memory[ptr]++;
							ptr += 9;
						}
						ptr -= 8;
						while(memory[ptr]) {
							ptr -= 9;
						}
					}
					ptr += 9;
					while(memory[ptr]) {
						ptr += 9;
					}
					ptr -= 9;
					while(memory[ptr]) {
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 9;
							memory[ptr]++;
							ptr -= 9;
						}
						ptr -= 10;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 9;
						memory[ptr]++;
						ptr -= 9;
					}
					ptr--;
					memory[ptr]++;
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr--;
					memory[ptr]--;
					ptr += 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 4;
						memory[ptr]++;
						ptr++;
						while(memory[ptr]) {
							ptr--;
							memory[ptr]--;
							ptr++;
							memory[ptr]--;
							ptr -= 6;
							memory[ptr]++;
							ptr += 6;
						}
						ptr--;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
							ptr--;
						}
						ptr += 4;
					}
					ptr -= 3;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 3;
						memory[ptr]++;
						ptr -= 3;
					}
					ptr--;
					memory[ptr]++;
					ptr -= 9;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr += 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 36;
						memory[ptr]++;
						ptr += 36;
					}
					ptr += 5;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr += 3;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 36;
						memory[ptr]++;
						ptr += 36;
					}
					ptr += 6;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				memory[ptr] += 15;
				while(memory[ptr]) {
					while(memory[ptr]) {
						ptr += 9;
					}
					ptr -= 9;
					memory[ptr]--;
					ptr -= 9;
					while(memory[ptr]) {
						ptr -= 9;
					}
					ptr += 9;
					memory[ptr]--;
				}
				memory[ptr]++;
				while(memory[ptr]) {
					ptr += 8;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 7;
						memory[ptr]++;
						ptr += 7;
					}
					ptr -= 7;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 7;
						memory[ptr]++;
						ptr -= 6;
						memory[ptr]++;
						ptr--;
					}
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr += 6;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr += 3;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 4;
				memory[ptr]++;
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr--;
					memory[ptr]--;
					ptr -= 4;
					memory[ptr]++;
					ptr += 5;
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 6;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 5;
						memory[ptr]++;
						ptr--;
						memory[ptr] += 2;
						ptr -= 4;
					}
					ptr += 5;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 5;
						memory[ptr]++;
						ptr += 5;
					}
					ptr--;
					memory[ptr]--;
					ptr++;
					memory[ptr]++;
					ptr++;
				}
				ptr--;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr++;
					memory[ptr]++;
					ptr--;
				}
				ptr -= 5;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 5;
					memory[ptr]++;
					ptr -= 5;
				}
				ptr += 6;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr -= 6;
				memory[ptr]++;
				ptr += 4;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 4;
					memory[ptr]--;
					ptr += 4;
				}
				memory[ptr]++;
				ptr -= 4;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 4;
					memory[ptr]--;
					ptr += 5;
					while(memory[ptr]) {
						ptr += 2;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr -= 2;
							memory[ptr]--;
							ptr += 2;
						}
						memory[ptr]++;
						ptr -= 2;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 2;
							memory[ptr]--;
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr -= 3;
								memory[ptr]++;
								ptr += 3;
							}
							ptr -= 3;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 3;
								memory[ptr]++;
								ptr -= 12;
								while(memory[ptr]) {
									ptr -= 9;
								}
								ptr += 3;
								while(memory[ptr]) {
									memory[ptr]--;
								}
								memory[ptr]++;
								ptr += 6;
								while(memory[ptr]) {
									ptr += 9;
								}
								ptr++;
								memory[ptr]++;
								ptr--;
							}
						}
						memory[ptr]++;
						ptr += 3;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr -= 3;
							memory[ptr]--;
							ptr += 3;
						}
						memory[ptr]++;
						ptr -= 3;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 3;
							memory[ptr]--;
							ptr--;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr -= 2;
								memory[ptr]++;
								ptr += 2;
							}
							ptr -= 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 2;
								memory[ptr]++;
								ptr -= 11;
								while(memory[ptr]) {
									ptr -= 9;
								}
								ptr += 4;
								while(memory[ptr]) {
									memory[ptr]--;
								}
								memory[ptr]++;
								ptr += 5;
								while(memory[ptr]) {
									ptr += 9;
								}
								ptr++;
								while(memory[ptr]) {
									memory[ptr]--;
								}
								memory[ptr]++;
								ptr--;
							}
						}
						memory[ptr]++;
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							while(memory[ptr]) {
								ptr += 9;
							}
							ptr -= 8;
						}
						ptr += 8;
					}
					ptr -= 9;
					while(memory[ptr]) {
						ptr -= 9;
					}
					ptr += 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 4;
						memory[ptr]++;
						ptr += 4;
					}
					ptr -= 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 4;
						memory[ptr]++;
						ptr += 5;
						while(memory[ptr]) {
							ptr++;
							memory[ptr]++;
							ptr += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr -= 2;
								memory[ptr]--;
								ptr += 2;
							}
							ptr -= 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 2;
								memory[ptr]++;
								ptr -= 2;
							}
							ptr += 8;
						}
						ptr -= 8;
						memory[ptr]++;
						ptr--;
						while(memory[ptr]) {
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 5;
								memory[ptr]++;
								ptr -= 4;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr += 4;
									memory[ptr]--;
									ptr -= 14;
									memory[ptr]++;
									ptr += 11;
									while(memory[ptr]) {
										memory[ptr]--;
										ptr += 3;
										memory[ptr]++;
										ptr -= 3;
									}
									ptr--;
								}
								ptr++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr += 3;
									memory[ptr]--;
									ptr -= 14;
									memory[ptr]++;
									ptr += 11;
								}
								ptr -= 2;
							}
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 4;
								memory[ptr]++;
								ptr -= 3;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr += 3;
									memory[ptr]--;
									ptr -= 14;
									memory[ptr]++;
									ptr += 11;
								}
								ptr--;
							}
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 3;
								memory[ptr]++;
								ptr -= 3;
							}
							ptr -= 12;
						}
						ptr += 4;
						while(memory[ptr]) {
							memory[ptr]--;
						}
						ptr -= 4;
					}
					ptr += 3;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 3;
						memory[ptr]++;
						ptr += 3;
					}
					ptr -= 3;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 3;
						memory[ptr]++;
						ptr += 6;
						while(memory[ptr]) {
							ptr++;
							memory[ptr]++;
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]--;
								ptr++;
							}
							ptr--;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
								ptr--;
							}
							ptr += 8;
						}
						ptr -= 8;
						memory[ptr]++;
						ptr--;
						while(memory[ptr]) {
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 5;
								memory[ptr]++;
								ptr -= 3;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr += 3;
									memory[ptr]--;
									ptr -= 14;
									memory[ptr]++;
									ptr += 10;
									while(memory[ptr]) {
										memory[ptr]--;
										ptr += 4;
										memory[ptr]++;
										ptr -= 4;
									}
									ptr++;
								}
								ptr--;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr += 4;
									memory[ptr]--;
									ptr -= 14;
									memory[ptr]++;
									ptr += 10;
								}
								ptr--;
							}
							ptr += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 3;
								memory[ptr]++;
								ptr -= 4;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr += 4;
									memory[ptr]--;
									ptr -= 14;
									memory[ptr]++;
									ptr += 10;
								}
								ptr++;
							}
							ptr--;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 4;
								memory[ptr]++;
								ptr -= 4;
							}
							ptr -= 11;
						}
						ptr += 6;
						memory[ptr]++;
						ptr -= 6;
					}
				}
				ptr += 4;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 4;
					memory[ptr]++;
					ptr += 4;
				}
				ptr -= 4;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 4;
					memory[ptr]++;
					ptr += 5;
					while(memory[ptr]) {
						ptr += 9;
					}
					ptr -= 9;
					while(memory[ptr]) {
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 5;
							memory[ptr]++;
							ptr -= 4;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 4;
								memory[ptr]--;
								ptr -= 14;
								memory[ptr]++;
								ptr += 11;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr += 3;
									memory[ptr]++;
									ptr -= 3;
								}
								ptr--;
							}
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 3;
								memory[ptr]--;
								ptr -= 14;
								memory[ptr]++;
								ptr += 11;
							}
							ptr -= 2;
						}
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 4;
							memory[ptr]++;
							ptr -= 3;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 3;
								memory[ptr]--;
								ptr -= 14;
								memory[ptr]++;
								ptr += 11;
							}
							ptr--;
						}
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 3;
							memory[ptr]++;
							ptr -= 3;
						}
						ptr -= 12;
					}
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr += 2;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr += 5;
				while(memory[ptr]) {
					ptr += 2;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr += 6;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr += 5;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 4;
						memory[ptr]++;
						ptr += 4;
					}
					ptr -= 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 4;
						memory[ptr]++;
						ptr -= 3;
						memory[ptr]++;
						ptr--;
					}
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				memory[ptr] += 15;
				while(memory[ptr]) {
					while(memory[ptr]) {
						ptr += 9;
					}
					memory[ptr]++;
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr -= 9;
					while(memory[ptr]) {
						ptr -= 9;
					}
					ptr += 9;
					memory[ptr]--;
				}
				memory[ptr]++;
				while(memory[ptr]) {
					ptr++;
					memory[ptr]++;
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr++;
					memory[ptr]--;
					ptr += 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 4;
						memory[ptr]++;
						ptr += 4;
					}
					ptr -= 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 4;
						memory[ptr]++;
						ptr -= 5;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr -= 2;
								memory[ptr]++;
								ptr += 2;
							}
							ptr -= 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 2;
								memory[ptr]++;
								ptr++;
								memory[ptr]++;
								ptr -= 3;
							}
							memory[ptr]++;
							ptr += 9;
						}
						ptr -= 8;
						while(memory[ptr]) {
							ptr -= 9;
						}
					}
					ptr += 9;
					while(memory[ptr]) {
						ptr += 9;
					}
					ptr -= 9;
					while(memory[ptr]) {
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 9;
							memory[ptr]++;
							ptr -= 9;
						}
						ptr -= 10;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 9;
						memory[ptr]++;
						ptr -= 9;
					}
					ptr--;
					memory[ptr]++;
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr--;
					memory[ptr]--;
					ptr += 3;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 3;
						memory[ptr]++;
						ptr++;
						while(memory[ptr]) {
							ptr--;
							memory[ptr]--;
							ptr++;
							memory[ptr]--;
							ptr -= 7;
							memory[ptr]++;
							ptr += 7;
						}
						ptr--;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
							ptr--;
						}
						ptr += 3;
					}
					ptr -= 2;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 2;
						memory[ptr]++;
						ptr -= 2;
					}
					ptr--;
					memory[ptr]++;
					ptr -= 9;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr += 3;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 36;
						memory[ptr]++;
						ptr += 36;
					}
					ptr += 6;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 5;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr += 4;
				memory[ptr] += 15;
				while(memory[ptr]) {
					while(memory[ptr]) {
						ptr += 9;
					}
					ptr -= 9;
					memory[ptr]--;
					ptr -= 9;
					while(memory[ptr]) {
						ptr -= 9;
					}
					ptr += 9;
					memory[ptr]--;
				}
				memory[ptr]++;
				while(memory[ptr]) {
					ptr += 3;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 3;
						memory[ptr]--;
						ptr += 3;
					}
					memory[ptr]++;
					ptr -= 3;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 3;
						memory[ptr]--;
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr -= 4;
							memory[ptr]++;
							ptr += 4;
						}
						ptr -= 4;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 4;
							memory[ptr]++;
							ptr -= 13;
							while(memory[ptr]) {
								ptr -= 9;
							}
							ptr += 4;
							while(memory[ptr]) {
								memory[ptr]--;
							}
							memory[ptr]++;
							ptr += 5;
							while(memory[ptr]) {
								ptr += 9;
							}
							ptr++;
							memory[ptr]++;
							ptr--;
						}
					}
					memory[ptr]++;
					ptr += 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 4;
						memory[ptr]--;
						ptr += 4;
					}
					memory[ptr]++;
					ptr -= 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 4;
						memory[ptr]--;
						ptr--;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr -= 3;
							memory[ptr]++;
							ptr += 3;
						}
						ptr -= 3;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 3;
							memory[ptr]++;
							ptr -= 12;
							while(memory[ptr]) {
								ptr -= 9;
							}
							ptr += 3;
							while(memory[ptr]) {
								memory[ptr]--;
							}
							memory[ptr]++;
							ptr += 6;
							while(memory[ptr]) {
								ptr += 9;
							}
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
							}
							memory[ptr]++;
							ptr--;
						}
					}
					memory[ptr]++;
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						while(memory[ptr]) {
							ptr += 9;
						}
						ptr -= 8;
					}
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 3;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 3;
					memory[ptr]++;
					ptr += 3;
				}
				ptr -= 3;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 3;
					memory[ptr]++;
					ptr += 6;
					while(memory[ptr]) {
						ptr++;
						memory[ptr]++;
						ptr += 3;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr -= 3;
							memory[ptr]--;
							ptr += 3;
						}
						ptr -= 3;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 3;
							memory[ptr]++;
							ptr -= 3;
						}
						ptr += 8;
					}
					ptr -= 8;
					memory[ptr]++;
					ptr--;
					while(memory[ptr]) {
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]--;
								ptr -= 10;
								memory[ptr]++;
								ptr += 12;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr -= 2;
									memory[ptr]++;
									ptr += 2;
								}
								ptr--;
							}
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr -= 2;
								memory[ptr]--;
								ptr -= 10;
								memory[ptr]++;
								ptr += 12;
							}
							ptr -= 3;
						}
						ptr += 2;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
							ptr += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr -= 2;
								memory[ptr]--;
								ptr -= 10;
								memory[ptr]++;
								ptr += 12;
							}
							ptr--;
						}
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr -= 2;
							memory[ptr]++;
							ptr += 2;
						}
						ptr -= 13;
					}
				}
				ptr += 4;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 4;
					memory[ptr]++;
					ptr += 4;
				}
				ptr -= 4;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 4;
					memory[ptr]++;
					ptr += 5;
					while(memory[ptr]) {
						ptr++;
						memory[ptr]++;
						ptr += 2;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr -= 2;
							memory[ptr]--;
							ptr += 2;
						}
						ptr -= 2;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 2;
							memory[ptr]++;
							ptr -= 2;
						}
						ptr += 8;
					}
					ptr -= 8;
					memory[ptr]++;
					ptr--;
					while(memory[ptr]) {
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
							ptr += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr -= 2;
								memory[ptr]--;
								ptr -= 10;
								memory[ptr]++;
								ptr += 11;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
									ptr++;
								}
								ptr++;
							}
							ptr--;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]--;
								ptr -= 10;
								memory[ptr]++;
								ptr += 11;
							}
							ptr -= 2;
						}
						ptr += 3;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr -= 2;
							memory[ptr]++;
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]--;
								ptr -= 10;
								memory[ptr]++;
								ptr += 11;
							}
							ptr++;
						}
						ptr--;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
							ptr++;
						}
						ptr -= 12;
					}
					ptr += 5;
					memory[ptr]++;
					ptr -= 5;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr += 3;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr += 4;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 3;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr += 5;
				while(memory[ptr]) {
					ptr += 7;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 6;
						memory[ptr]++;
						ptr += 6;
					}
					ptr -= 6;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 6;
						memory[ptr]++;
						ptr -= 4;
						memory[ptr]++;
						ptr -= 2;
					}
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 4;
				memory[ptr]++;
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr--;
					memory[ptr]--;
					ptr -= 4;
					memory[ptr]++;
					ptr += 5;
				}
				ptr += 2;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 7;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 5;
						memory[ptr]++;
						ptr--;
						memory[ptr] += 2;
						ptr -= 4;
					}
					ptr += 5;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 5;
						memory[ptr]++;
						ptr += 5;
					}
					ptr--;
					memory[ptr]--;
					ptr++;
					memory[ptr]++;
					ptr += 2;
				}
				ptr -= 2;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 2;
					memory[ptr]++;
					ptr -= 2;
				}
				ptr -= 5;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 5;
					memory[ptr]++;
					ptr -= 5;
				}
				memory[ptr]++;
				ptr += 4;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 4;
					memory[ptr]--;
					ptr += 4;
				}
				memory[ptr]++;
				ptr -= 4;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 4;
					memory[ptr]--;
					ptr += 5;
					while(memory[ptr]) {
						ptr += 3;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr -= 3;
							memory[ptr]--;
							ptr += 3;
						}
						memory[ptr]++;
						ptr -= 3;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 3;
							memory[ptr]--;
							ptr--;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr -= 2;
								memory[ptr]++;
								ptr += 2;
							}
							ptr -= 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 2;
								memory[ptr]++;
								ptr -= 11;
								while(memory[ptr]) {
									ptr -= 9;
								}
								ptr += 4;
								while(memory[ptr]) {
									memory[ptr]--;
								}
								memory[ptr]++;
								ptr += 5;
								while(memory[ptr]) {
									ptr += 9;
								}
								ptr++;
								memory[ptr]++;
								ptr--;
							}
						}
						memory[ptr]++;
						ptr += 2;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr -= 2;
							memory[ptr]--;
							ptr += 2;
						}
						memory[ptr]++;
						ptr -= 2;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 2;
							memory[ptr]--;
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr -= 3;
								memory[ptr]++;
								ptr += 3;
							}
							ptr -= 3;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 3;
								memory[ptr]++;
								ptr -= 12;
								while(memory[ptr]) {
									ptr -= 9;
								}
								ptr += 3;
								while(memory[ptr]) {
									memory[ptr]--;
								}
								memory[ptr]++;
								ptr += 6;
								while(memory[ptr]) {
									ptr += 9;
								}
								ptr++;
								while(memory[ptr]) {
									memory[ptr]--;
								}
								memory[ptr]++;
								ptr--;
							}
						}
						memory[ptr]++;
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							while(memory[ptr]) {
								ptr += 9;
							}
							ptr -= 8;
						}
						ptr += 8;
					}
					ptr -= 9;
					while(memory[ptr]) {
						ptr -= 9;
					}
					ptr += 3;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 3;
						memory[ptr]++;
						ptr += 3;
					}
					ptr -= 3;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 3;
						memory[ptr]++;
						ptr += 6;
						while(memory[ptr]) {
							ptr++;
							memory[ptr]++;
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]--;
								ptr++;
							}
							ptr--;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
								ptr--;
							}
							ptr += 8;
						}
						ptr -= 8;
						memory[ptr]++;
						ptr--;
						while(memory[ptr]) {
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 4;
								memory[ptr]++;
								ptr -= 2;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr += 2;
									memory[ptr]--;
									ptr -= 13;
									memory[ptr]++;
									ptr += 10;
									while(memory[ptr]) {
										memory[ptr]--;
										ptr += 3;
										memory[ptr]++;
										ptr -= 3;
									}
									ptr++;
								}
								ptr--;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr += 3;
									memory[ptr]--;
									ptr -= 13;
									memory[ptr]++;
									ptr += 10;
								}
								ptr--;
							}
							ptr += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 2;
								memory[ptr]++;
								ptr -= 3;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr += 3;
									memory[ptr]--;
									ptr -= 13;
									memory[ptr]++;
									ptr += 10;
								}
								ptr++;
							}
							ptr--;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 3;
								memory[ptr]++;
								ptr -= 3;
							}
							ptr -= 11;
						}
						ptr += 5;
						while(memory[ptr]) {
							memory[ptr]--;
						}
						ptr += 2;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr -= 7;
							memory[ptr]++;
							ptr += 7;
						}
						ptr -= 7;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 7;
							memory[ptr]++;
							ptr -= 2;
							memory[ptr]++;
							ptr -= 5;
						}
					}
					ptr += 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 4;
						memory[ptr]++;
						ptr += 4;
					}
					ptr -= 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 4;
						memory[ptr]++;
						ptr += 5;
						while(memory[ptr]) {
							ptr++;
							memory[ptr]++;
							ptr += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr -= 2;
								memory[ptr]--;
								ptr += 2;
							}
							ptr -= 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 2;
								memory[ptr]++;
								ptr -= 2;
							}
							ptr += 8;
						}
						ptr -= 8;
						memory[ptr]++;
						ptr--;
						while(memory[ptr]) {
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 4;
								memory[ptr]++;
								ptr -= 3;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr += 3;
									memory[ptr]--;
									ptr -= 13;
									memory[ptr]++;
									ptr += 11;
									while(memory[ptr]) {
										memory[ptr]--;
										ptr += 2;
										memory[ptr]++;
										ptr -= 2;
									}
									ptr--;
								}
								ptr++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr += 2;
									memory[ptr]--;
									ptr -= 13;
									memory[ptr]++;
									ptr += 11;
								}
								ptr -= 2;
							}
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 3;
								memory[ptr]++;
								ptr -= 2;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr += 2;
									memory[ptr]--;
									ptr -= 13;
									memory[ptr]++;
									ptr += 11;
								}
								ptr--;
							}
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 2;
								memory[ptr]++;
								ptr -= 2;
							}
							ptr -= 12;
						}
					}
					ptr += 4;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr -= 4;
				}
				ptr += 4;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 4;
					memory[ptr]++;
					ptr += 4;
				}
				ptr -= 4;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 4;
					memory[ptr]++;
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr += 2;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 7;
						memory[ptr]++;
						ptr += 7;
					}
					ptr -= 7;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 7;
						memory[ptr]++;
						ptr -= 2;
						memory[ptr]++;
						ptr -= 5;
					}
					ptr += 9;
					while(memory[ptr]) {
						ptr += 9;
					}
					ptr -= 9;
					while(memory[ptr]) {
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 4;
							memory[ptr]++;
							ptr -= 3;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 3;
								memory[ptr]--;
								ptr -= 13;
								memory[ptr]++;
								ptr += 11;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr += 2;
									memory[ptr]++;
									ptr -= 2;
								}
								ptr--;
							}
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 2;
								memory[ptr]--;
								ptr -= 13;
								memory[ptr]++;
								ptr += 11;
							}
							ptr -= 2;
						}
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 3;
							memory[ptr]++;
							ptr -= 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 2;
								memory[ptr]--;
								ptr -= 13;
								memory[ptr]++;
								ptr += 11;
							}
							ptr--;
						}
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 2;
							memory[ptr]++;
							ptr -= 2;
						}
						ptr -= 12;
					}
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr += 2;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr += 6;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 3;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr += 5;
				while(memory[ptr]) {
					ptr += 5;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 4;
						memory[ptr]++;
						ptr += 4;
					}
					ptr -= 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 4;
						memory[ptr]++;
						ptr -= 3;
						memory[ptr]++;
						ptr--;
					}
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr += 6;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 5;
						memory[ptr]++;
						ptr += 5;
					}
					ptr -= 5;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 5;
						memory[ptr]++;
						ptr -= 3;
						memory[ptr]++;
						ptr -= 2;
					}
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				memory[ptr] += 15;
				while(memory[ptr]) {
					while(memory[ptr]) {
						ptr += 9;
					}
					memory[ptr]++;
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr -= 9;
					while(memory[ptr]) {
						ptr -= 9;
					}
					ptr += 9;
					memory[ptr]--;
				}
				memory[ptr]++;
				while(memory[ptr]) {
					ptr++;
					memory[ptr]++;
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr++;
					memory[ptr]--;
					ptr += 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 4;
						memory[ptr]++;
						ptr += 4;
					}
					ptr -= 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 4;
						memory[ptr]++;
						ptr -= 5;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr -= 2;
								memory[ptr]++;
								ptr += 2;
							}
							ptr -= 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 2;
								memory[ptr]++;
								ptr += 2;
								memory[ptr]++;
								ptr -= 4;
							}
							memory[ptr]++;
							ptr += 9;
						}
						ptr -= 8;
						while(memory[ptr]) {
							ptr -= 9;
						}
					}
					ptr += 9;
					while(memory[ptr]) {
						ptr += 9;
					}
					ptr -= 9;
					while(memory[ptr]) {
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 9;
							memory[ptr]++;
							ptr -= 9;
						}
						ptr -= 10;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 9;
						memory[ptr]++;
						ptr -= 9;
					}
					ptr--;
					memory[ptr]++;
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr--;
					memory[ptr]--;
					ptr += 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 4;
						memory[ptr]++;
						ptr++;
						while(memory[ptr]) {
							ptr--;
							memory[ptr]--;
							ptr++;
							memory[ptr]--;
							ptr -= 6;
							memory[ptr]++;
							ptr += 6;
						}
						ptr--;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
							ptr--;
						}
						ptr += 4;
					}
					ptr -= 3;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 3;
						memory[ptr]++;
						ptr -= 3;
					}
					ptr--;
					memory[ptr]++;
					ptr -= 9;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr++;
					memory[ptr]++;
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr++;
					memory[ptr]--;
					ptr += 5;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 5;
						memory[ptr]++;
						ptr += 5;
					}
					ptr -= 5;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 5;
						memory[ptr]++;
						ptr -= 6;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 3;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr -= 3;
								memory[ptr]++;
								ptr += 3;
							}
							ptr -= 3;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr += 3;
								memory[ptr]++;
								ptr++;
								memory[ptr]++;
								ptr -= 4;
							}
							memory[ptr]++;
							ptr += 9;
						}
						ptr -= 8;
						while(memory[ptr]) {
							ptr -= 9;
						}
					}
					ptr += 9;
					while(memory[ptr]) {
						ptr += 9;
					}
					ptr -= 9;
					while(memory[ptr]) {
						ptr += 2;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 9;
							memory[ptr]++;
							ptr -= 9;
						}
						ptr -= 11;
					}
					ptr += 2;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 9;
						memory[ptr]++;
						ptr -= 9;
					}
					ptr -= 2;
					memory[ptr]++;
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr--;
					memory[ptr]--;
					ptr += 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 4;
						memory[ptr]++;
						ptr++;
						while(memory[ptr]) {
							ptr--;
							memory[ptr]--;
							ptr++;
							memory[ptr]--;
							ptr -= 6;
							memory[ptr]++;
							ptr += 6;
						}
						ptr--;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
							ptr--;
						}
						ptr += 4;
					}
					ptr -= 3;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 3;
						memory[ptr]++;
						ptr -= 3;
					}
					ptr--;
					memory[ptr]++;
					ptr -= 9;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr += 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 36;
						memory[ptr]++;
						ptr += 36;
					}
					ptr += 5;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				memory[ptr] += 15;
				while(memory[ptr]) {
					while(memory[ptr]) {
						ptr += 9;
					}
					ptr -= 9;
					memory[ptr]--;
					ptr -= 9;
					while(memory[ptr]) {
						ptr -= 9;
					}
					ptr += 9;
					memory[ptr]--;
				}
				memory[ptr]++;
				ptr += 21;
				memory[ptr]++;
				ptr -= 3;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr += 3;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 3;
						memory[ptr]--;
						ptr += 3;
					}
					memory[ptr]++;
					ptr -= 3;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 3;
						memory[ptr]--;
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr -= 4;
							memory[ptr]++;
							ptr += 4;
						}
						ptr -= 4;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 4;
							memory[ptr]++;
							ptr -= 13;
							while(memory[ptr]) {
								ptr -= 9;
							}
							ptr += 4;
							while(memory[ptr]) {
								memory[ptr]--;
							}
							memory[ptr]++;
							ptr += 5;
							while(memory[ptr]) {
								ptr += 9;
							}
							ptr++;
							memory[ptr]++;
							ptr--;
						}
					}
					memory[ptr]++;
					ptr += 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 4;
						memory[ptr]--;
						ptr += 4;
					}
					memory[ptr]++;
					ptr -= 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 4;
						memory[ptr]--;
						ptr--;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr -= 3;
							memory[ptr]++;
							ptr += 3;
						}
						ptr -= 3;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 3;
							memory[ptr]++;
							ptr -= 12;
							while(memory[ptr]) {
								ptr -= 9;
							}
							ptr += 3;
							while(memory[ptr]) {
								memory[ptr]--;
							}
							memory[ptr]++;
							ptr += 6;
							while(memory[ptr]) {
								ptr += 9;
							}
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
							}
							memory[ptr]++;
							ptr--;
						}
					}
					memory[ptr]++;
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						while(memory[ptr]) {
							ptr += 9;
						}
						ptr -= 8;
					}
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 2;
				memory[ptr]--;
				ptr += 2;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 4;
					memory[ptr]++;
					ptr += 4;
				}
				ptr -= 4;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 4;
					memory[ptr]++;
					ptr -= 2;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr -= 2;
				}
				ptr += 2;
			}
			ptr -= 2;
			memory[ptr]++;
			ptr += 4;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr -= 4;
				memory[ptr]--;
				ptr += 4;
			}
			memory[ptr]++;
			ptr -= 4;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr += 4;
				memory[ptr]--;
				ptr -= 6;
				putchar(memory[ptr]);				ptr += 2;
			}
			ptr += 4;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr -= 7;
				putchar(memory[ptr]);				ptr += 7;
			}
			ptr -= 3;
			while(memory[ptr]) {
				memory[ptr]--;
			}
			ptr++;
			while(memory[ptr]) {
				memory[ptr]--;
			}
			ptr++;
			while(memory[ptr]) {
				memory[ptr]--;
			}
			ptr++;
			while(memory[ptr]) {
				memory[ptr]--;
			}
			ptr++;
			while(memory[ptr]) {
				memory[ptr]--;
			}
			ptr++;
			while(memory[ptr]) {
				memory[ptr]--;
			}
			ptr += 3;
			while(memory[ptr]) {
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr += 3;
			}
			ptr -= 9;
			while(memory[ptr]) {
				ptr -= 9;
			}
			ptr += 9;
			while(memory[ptr]) {
				ptr += 5;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr += 4;
			}
			ptr -= 9;
			while(memory[ptr]) {
				ptr -= 9;
			}
			ptr++;
			memory[ptr] += 11;
			while(memory[ptr]) {
				memory[ptr]--;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 9;
					memory[ptr]++;
					ptr -= 9;
				}
				ptr += 9;
			}
			ptr += 4;
			memory[ptr]++;
			ptr += 9;
			memory[ptr]++;
			ptr -= 14;
			while(memory[ptr]) {
				ptr -= 9;
			}
			ptr += 7;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr -= 7;
				memory[ptr]++;
				ptr += 7;
			}
			ptr -= 7;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr += 7;
				memory[ptr]++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr += 2;
				while(memory[ptr]) {
					ptr += 9;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr += 7;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 6;
						memory[ptr]++;
						ptr += 6;
					}
					ptr -= 6;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 6;
						memory[ptr]++;
						ptr -= 7;
						while(memory[ptr]) {
							ptr -= 9;
						}
						ptr += 7;
						while(memory[ptr]) {
							memory[ptr]--;
						}
						memory[ptr]++;
						ptr += 3;
					}
					ptr -= 10;
				}
			}
			ptr += 7;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr -= 7;
				memory[ptr]++;
				ptr += 7;
			}
			ptr -= 7;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr += 7;
				memory[ptr]++;
				ptr += 2;
				while(memory[ptr]) {
					ptr++;
					memory[ptr]++;
					ptr += 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 4;
						memory[ptr]--;
						ptr += 4;
					}
					ptr -= 4;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 4;
						memory[ptr]++;
						ptr -= 4;
					}
					ptr += 8;
				}
				ptr -= 2;
				memory[ptr]++;
				ptr -= 7;
				while(memory[ptr]) {
					ptr += 5;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 2;
						memory[ptr]++;
						ptr -= 2;
					}
					ptr -= 14;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr += 9;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr--;
					memory[ptr]--;
					ptr += 7;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 7;
						memory[ptr]++;
						ptr++;
						while(memory[ptr]) {
							ptr--;
							memory[ptr]--;
							ptr++;
							memory[ptr]--;
							ptr -= 3;
							memory[ptr]++;
							ptr += 3;
						}
						ptr--;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
							ptr--;
						}
						ptr += 7;
					}
					ptr -= 6;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 6;
						memory[ptr]++;
						ptr -= 6;
					}
					ptr--;
					memory[ptr]++;
					ptr -= 9;
				}
				ptr += 7;
				memory[ptr]--;
				ptr -= 4;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				memory[ptr]++;
				ptr -= 3;
			}
			memory[ptr]++;
			ptr += 7;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr -= 7;
				memory[ptr]--;
				ptr += 7;
			}
			memory[ptr]++;
			ptr -= 7;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr += 7;
				memory[ptr]--;
				ptr += 2;
				while(memory[ptr]) {
					ptr += 5;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 2;
						memory[ptr]++;
						ptr -= 2;
					}
					ptr += 4;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					ptr--;
					memory[ptr]--;
					ptr += 7;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 7;
						memory[ptr]++;
						ptr++;
						while(memory[ptr]) {
							ptr--;
							memory[ptr]--;
							ptr++;
							memory[ptr]--;
							ptr -= 3;
							memory[ptr]++;
							ptr += 3;
						}
						ptr--;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
							ptr--;
						}
						ptr += 7;
					}
					ptr -= 6;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 6;
						memory[ptr]++;
						ptr -= 6;
					}
					ptr--;
					memory[ptr]++;
					ptr -= 9;
				}
				ptr++;
				memory[ptr] += 5;
				while(memory[ptr]) {
					memory[ptr]--;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 9;
						memory[ptr]++;
						ptr -= 9;
					}
					ptr += 9;
				}
				ptr += 4;
				memory[ptr]++;
				ptr -= 5;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 9;
				while(memory[ptr]) {
					ptr += 5;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 5;
						memory[ptr]--;
						ptr += 5;
					}
					memory[ptr]++;
					ptr -= 5;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 5;
						memory[ptr]--;
						ptr += 2;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr -= 7;
							memory[ptr]++;
							ptr += 7;
						}
						ptr -= 7;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 7;
							memory[ptr]++;
							ptr -= 16;
							while(memory[ptr]) {
								ptr -= 9;
							}
							ptr += 4;
							while(memory[ptr]) {
								memory[ptr]--;
							}
							memory[ptr]++;
							ptr += 5;
							while(memory[ptr]) {
								ptr += 9;
							}
							ptr++;
							memory[ptr]++;
							ptr--;
						}
					}
					memory[ptr]++;
					ptr += 7;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 7;
						memory[ptr]--;
						ptr += 7;
					}
					memory[ptr]++;
					ptr -= 7;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 7;
						memory[ptr]--;
						ptr -= 2;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr -= 5;
							memory[ptr]++;
							ptr += 5;
						}
						ptr -= 5;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr += 5;
							memory[ptr]++;
							ptr -= 14;
							while(memory[ptr]) {
								ptr -= 9;
							}
							ptr += 3;
							while(memory[ptr]) {
								memory[ptr]--;
							}
							memory[ptr]++;
							ptr += 6;
							while(memory[ptr]) {
								ptr += 9;
							}
							ptr++;
							while(memory[ptr]) {
								memory[ptr]--;
							}
							memory[ptr]++;
							ptr--;
						}
					}
					memory[ptr]++;
					ptr++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						while(memory[ptr]) {
							ptr += 9;
						}
						ptr -= 8;
					}
					ptr += 8;
				}
				ptr -= 9;
				while(memory[ptr]) {
					ptr -= 9;
				}
				ptr += 4;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr -= 3;
				memory[ptr] += 5;
				while(memory[ptr]) {
					memory[ptr]--;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 9;
						memory[ptr]++;
						ptr -= 9;
					}
					ptr += 9;
				}
				ptr += 4;
				memory[ptr]--;
				ptr -= 5;
				while(memory[ptr]) {
					ptr -= 9;
				}
			}
			ptr += 3;
		}
		ptr -= 4;
		putchar(memory[ptr]);		ptr += 10;
		while(memory[ptr]) {
			ptr += 6;
			while(memory[ptr]) {
				memory[ptr]--;
			}
			ptr += 3;
		}
		ptr -= 9;
		while(memory[ptr]) {
			ptr -= 9;
		}
		ptr++;
		memory[ptr] += 10;
		while(memory[ptr]) {
			memory[ptr]--;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr += 9;
				memory[ptr]++;
				ptr -= 9;
			}
			ptr += 9;
		}
		ptr += 5;
		memory[ptr]++;
		ptr += 9;
		memory[ptr]++;
		ptr -= 15;
		while(memory[ptr]) {
			ptr -= 9;
		}
		ptr += 8;
		while(memory[ptr]) {
			memory[ptr]--;
			ptr -= 8;
			memory[ptr]++;
			ptr += 8;
		}
		ptr -= 8;
		while(memory[ptr]) {
			memory[ptr]--;
			ptr += 8;
			memory[ptr]++;
			while(memory[ptr]) {
				memory[ptr]--;
			}
			ptr++;
			while(memory[ptr]) {
				ptr += 9;
			}
			ptr -= 9;
			while(memory[ptr]) {
				ptr += 8;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 7;
					memory[ptr]++;
					ptr += 7;
				}
				ptr -= 7;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 7;
					memory[ptr]++;
					ptr -= 8;
					while(memory[ptr]) {
						ptr -= 9;
					}
					ptr += 8;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					memory[ptr]++;
					ptr += 2;
				}
				ptr -= 10;
			}
		}
		ptr += 8;
		while(memory[ptr]) {
			memory[ptr]--;
			ptr -= 8;
			memory[ptr]++;
			ptr += 8;
		}
		ptr -= 8;
		while(memory[ptr]) {
			memory[ptr]--;
			ptr += 8;
			memory[ptr]++;
			ptr++;
			while(memory[ptr]) {
				ptr++;
				memory[ptr]++;
				ptr += 5;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 5;
					memory[ptr]--;
					ptr += 5;
				}
				ptr -= 5;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 5;
					memory[ptr]++;
					ptr -= 5;
				}
				ptr += 8;
			}
			ptr--;
			memory[ptr]++;
			ptr -= 8;
			while(memory[ptr]) {
				ptr += 6;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 2;
					memory[ptr]++;
					ptr -= 2;
				}
				ptr -= 15;
			}
			ptr += 9;
			while(memory[ptr]) {
				ptr += 9;
			}
			ptr -= 9;
			while(memory[ptr]) {
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr--;
				memory[ptr]--;
				ptr += 8;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 8;
					memory[ptr]++;
					ptr++;
					while(memory[ptr]) {
						ptr--;
						memory[ptr]--;
						ptr++;
						memory[ptr]--;
						ptr -= 2;
						memory[ptr]++;
						ptr += 2;
					}
					ptr--;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr++;
						memory[ptr]++;
						ptr--;
					}
					ptr += 8;
				}
				ptr -= 7;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 7;
					memory[ptr]++;
					ptr -= 7;
				}
				ptr--;
				memory[ptr]++;
				ptr -= 9;
			}
			ptr += 8;
			memory[ptr]--;
			ptr -= 5;
			while(memory[ptr]) {
				memory[ptr]--;
			}
			memory[ptr]++;
			ptr -= 3;
		}
		memory[ptr]++;
		ptr += 8;
		while(memory[ptr]) {
			memory[ptr]--;
			ptr -= 8;
			memory[ptr]--;
			ptr += 8;
		}
		memory[ptr]++;
		ptr -= 8;
		while(memory[ptr]) {
			memory[ptr]--;
			ptr += 8;
			memory[ptr]--;
			ptr++;
			while(memory[ptr]) {
				ptr += 6;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 2;
					memory[ptr]++;
					ptr -= 2;
				}
				ptr += 3;
			}
			ptr -= 9;
			while(memory[ptr]) {
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
				}
				ptr--;
				memory[ptr]--;
				ptr += 8;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 8;
					memory[ptr]++;
					ptr++;
					while(memory[ptr]) {
						ptr--;
						memory[ptr]--;
						ptr++;
						memory[ptr]--;
						ptr -= 2;
						memory[ptr]++;
						ptr += 2;
					}
					ptr--;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr++;
						memory[ptr]++;
						ptr--;
					}
					ptr += 8;
				}
				ptr -= 7;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 7;
					memory[ptr]++;
					ptr -= 7;
				}
				ptr--;
				memory[ptr]++;
				ptr -= 9;
			}
			ptr++;
			memory[ptr] += 5;
			while(memory[ptr]) {
				memory[ptr]--;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 9;
					memory[ptr]++;
					ptr -= 9;
				}
				ptr += 9;
			}
			ptr += 5;
			memory[ptr]++;
			ptr += 27;
			memory[ptr]++;
			ptr -= 6;
			while(memory[ptr]) {
				ptr -= 9;
			}
			ptr += 9;
			while(memory[ptr]) {
				ptr += 6;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 6;
					memory[ptr]--;
					ptr += 6;
				}
				memory[ptr]++;
				ptr -= 6;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 6;
					memory[ptr]--;
					ptr += 2;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 8;
						memory[ptr]++;
						ptr += 8;
					}
					ptr -= 8;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 8;
						memory[ptr]++;
						ptr -= 17;
						while(memory[ptr]) {
							ptr -= 9;
						}
						ptr += 4;
						while(memory[ptr]) {
							memory[ptr]--;
						}
						memory[ptr]++;
						ptr += 5;
						while(memory[ptr]) {
							ptr += 9;
						}
						ptr++;
						memory[ptr]++;
						ptr--;
					}
				}
				memory[ptr]++;
				ptr += 8;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 8;
					memory[ptr]--;
					ptr += 8;
				}
				memory[ptr]++;
				ptr -= 8;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 8;
					memory[ptr]--;
					ptr -= 2;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr -= 6;
						memory[ptr]++;
						ptr += 6;
					}
					ptr -= 6;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr += 6;
						memory[ptr]++;
						ptr -= 15;
						while(memory[ptr]) {
							ptr -= 9;
						}
						ptr += 3;
						while(memory[ptr]) {
							memory[ptr]--;
						}
						memory[ptr]++;
						ptr += 6;
						while(memory[ptr]) {
							ptr += 9;
						}
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
						}
						memory[ptr]++;
						ptr--;
					}
				}
				memory[ptr]++;
				ptr++;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr--;
					while(memory[ptr]) {
						ptr += 9;
					}
					ptr -= 8;
				}
				ptr += 8;
			}
			ptr -= 9;
			while(memory[ptr]) {
				ptr -= 9;
			}
			ptr += 4;
			while(memory[ptr]) {
				memory[ptr]--;
			}
			ptr -= 3;
			memory[ptr] += 5;
			while(memory[ptr]) {
				memory[ptr]--;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr += 9;
					memory[ptr]++;
					ptr -= 9;
				}
				ptr += 9;
			}
			ptr += 5;
			memory[ptr]--;
			ptr += 27;
			memory[ptr]--;
			ptr -= 6;
			while(memory[ptr]) {
				ptr -= 9;
			}
		}
		ptr += 3;
	}

	return EXIT_SUCCESS;
}