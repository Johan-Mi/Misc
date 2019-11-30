#include <stdio.h>

int main() {
	unsigned short ptr = 0;
	unsigned char memory[65536] = {0};

	memory[ptr]++;
	ptr++;
	memory[ptr]--;
	while(memory[ptr]) {
		ptr += 40;
		memory[ptr] += 2;
		memory[ptr] = 0;
		memory[ptr]--;
		ptr += 4;
		memory[ptr]++;
		ptr += 3;
		memory[ptr]++;
		ptr += 3;
		memory[ptr]++;
		ptr += 3;
		memory[ptr]++;
		ptr += 3;
		memory[ptr]++;
		ptr += 3;
		memory[ptr]++;
		ptr += 3;
		memory[ptr]++;
		ptr += 3;
		memory[ptr]++;
		ptr += 3;
		memory[ptr] += 2;
		while(memory[ptr]) {
			memory[ptr]--;
			ptr--;
			memory[ptr]++;
		}
		memory[ptr]--;
		ptr -= 4;
		memory[ptr]++;
		ptr -= 2;
		memory[ptr] += 4;
		while(memory[ptr]) {
			memory[ptr]--;
			ptr++;
			memory[ptr] += 8;
			ptr--;
		}
		ptr--;
		memory[ptr] += 2;
		while(memory[ptr]) {
			memory[ptr] -= 6;
			ptr++;
			memory[ptr]++;
			ptr--;
		}
		ptr++;
		memory[ptr] += 2;
		ptr -= 2;
		memory[ptr]++;
		while(memory[ptr]) {
			memory[ptr] -= 3;
			ptr++;
			memory[ptr] += 2;
			ptr--;
		}
		ptr++;
		memory[ptr] += 2;
		ptr -= 2;
		memory[ptr]--;
		while(memory[ptr]) {
			memory[ptr] -= 3;
			ptr++;
			memory[ptr]++;
			ptr--;
		}
		ptr++;
		memory[ptr] -= 6;
		ptr--;
		memory[ptr]++;
		while(memory[ptr]) {
			memory[ptr]--;
			ptr--;
			memory[ptr]++;
		}
		memory[ptr]--;
		ptr--;
		while(memory[ptr]) {
			ptr += 2;
			memory[ptr]++;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr++;
				memory[ptr]++;
			}
			memory[ptr]--;
			ptr--;
			memory[ptr] = 0;
			ptr -= 2;
			memory[ptr] = 0;
			memory[ptr] += 3;
			while(memory[ptr]) {
				ptr++;
				memory[ptr] = 0;
				memory[ptr] += 10;
				putchar(memory[ptr]);
				memory[ptr] = 0;
				memory[ptr] += 3;
				while(memory[ptr]) {
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						ptr += 2;
						memory[ptr]++;
						ptr -= 2;
						memory[ptr]--;
					}
					ptr += 2;
					while(memory[ptr]) {
						ptr -= 2;
						memory[ptr] += 2;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr++;
						memory[ptr] += 2;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr++;
						memory[ptr]--;
					}
					ptr -= 2;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr++;
					memory[ptr]--;
					while(memory[ptr]) {
						memory[ptr]--;
						while(memory[ptr]) {
							memory[ptr]--;
							while(memory[ptr]) {
								memory[ptr]--;
								while(memory[ptr]) {
									memory[ptr]--;
									while(memory[ptr]) {
										memory[ptr]--;
										while(memory[ptr]) {
											memory[ptr]--;
											while(memory[ptr]) {
												memory[ptr]--;
												while(memory[ptr]) {
													memory[ptr]--;
													ptr += 3;
												}
												ptr += 3;
											}
											ptr += 3;
										}
										ptr += 3;
									}
									ptr += 3;
								}
								ptr += 3;
							}
							ptr += 3;
						}
						ptr += 3;
					}
					ptr += 43;
					while(memory[ptr]) {
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr -= 6;
						putchar(memory[ptr]);
						ptr += 7;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr -= 7;
						putchar(memory[ptr]);
						ptr += 8;
					}
					ptr++;
					while(memory[ptr]) {
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr -= 8;
						putchar(memory[ptr]);
						ptr += 9;
					}
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr -= 5;
					putchar(memory[ptr]);
					ptr += 3;
					memory[ptr]--;
				}
				ptr--;
				memory[ptr]--;
			}
			memory[ptr] += 10;
			putchar(memory[ptr]);
			memory[ptr] = 0;
			ptr -= 6;
			while(memory[ptr]) {
				ptr -= 11;
				memory[ptr]++;
				while(memory[ptr]) {
					memory[ptr] -= 3;
					ptr++;
					memory[ptr] += 2;
					ptr--;
				}
				ptr++;
				memory[ptr] += 3;
				putchar(memory[ptr]);
				while(memory[ptr]) {
					memory[ptr]--;
					ptr++;
					memory[ptr] += 7;
					ptr--;
				}
				ptr++;
				putchar(memory[ptr]);
				memory[ptr] += 6;
				putchar(memory[ptr]);
				memory[ptr]--;
				while(memory[ptr]) {
					memory[ptr] -= 4;
					ptr++;
					memory[ptr]++;
					ptr--;
				}
				ptr++;
				memory[ptr] += 3;
				putchar(memory[ptr]);
				memory[ptr] -= 3;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr++;
					memory[ptr] += 3;
					ptr--;
				}
				while(memory[ptr]) {
					putchar(memory[ptr]);
				}
				ptr++;
				putchar(memory[ptr]);
				memory[ptr] += 3;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr++;
					memory[ptr] += 4;
					ptr--;
				}
				ptr++;
				memory[ptr]++;
				putchar(memory[ptr]);
				memory[ptr] += 5;
				putchar(memory[ptr]);
				memory[ptr]--;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr++;
					memory[ptr] += 5;
					ptr--;
				}
				ptr++;
				putchar(memory[ptr]);
				while(memory[ptr]) {
					memory[ptr] -= 3;
					ptr++;
					memory[ptr]++;
					ptr--;
				}
				ptr++;
				memory[ptr]--;
				putchar(memory[ptr]);
				memory[ptr]++;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr--;
					memory[ptr]++;
				}
				memory[ptr]--;
				ptr--;
				memory[ptr] = 0;
				ptr += 4;
			}
			ptr--;
			while(memory[ptr]) {
				ptr -= 7;
				memory[ptr] += 4;
				while(memory[ptr]) {
					memory[ptr] += 4;
					ptr++;
					memory[ptr] -= 3;
					ptr--;
				}
				ptr++;
				memory[ptr]++;
				putchar(memory[ptr]);
				while(memory[ptr]) {
					memory[ptr] += 4;
					ptr++;
					memory[ptr] -= 3;
					ptr--;
				}
				ptr++;
				memory[ptr]--;
				putchar(memory[ptr]);
				memory[ptr] += 3;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr++;
					memory[ptr] += 3;
					ptr--;
				}
				ptr++;
				memory[ptr] += 2;
				putchar(memory[ptr]);
				memory[ptr]++;
				while(memory[ptr]) {
					memory[ptr] -= 3;
					ptr++;
					memory[ptr]++;
					ptr--;
				}
				ptr++;
				memory[ptr]++;
				putchar(memory[ptr]);
				memory[ptr]++;
				while(memory[ptr]) {
					memory[ptr] -= 4;
					ptr++;
					memory[ptr]++;
					ptr--;
				}
				ptr++;
				memory[ptr] += 3;
				putchar(memory[ptr]);
				while(memory[ptr]) {
					memory[ptr] -= 3;
					ptr++;
					memory[ptr]++;
					ptr--;
				}
				ptr++;
				memory[ptr]--;
				putchar(memory[ptr]);
				memory[ptr] = 0;
				memory[ptr]++;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr--;
					memory[ptr]++;
				}
				memory[ptr]--;
				ptr--;
				memory[ptr] = 0;
				ptr += 4;
			}
			ptr--;
			while(memory[ptr]) {
				ptr -= 10;
				memory[ptr]++;
				while(memory[ptr]) {
					memory[ptr] -= 3;
					ptr++;
					memory[ptr] += 2;
					ptr--;
				}
				ptr++;
				memory[ptr] += 3;
				putchar(memory[ptr]);
				while(memory[ptr]) {
					memory[ptr]--;
					ptr++;
					memory[ptr] += 7;
					ptr--;
				}
				ptr++;
				putchar(memory[ptr]);
				memory[ptr] += 6;
				putchar(memory[ptr]);
				memory[ptr]--;
				while(memory[ptr]) {
					memory[ptr] -= 4;
					ptr++;
					memory[ptr]++;
					ptr--;
				}
				ptr++;
				memory[ptr] += 3;
				putchar(memory[ptr]);
				memory[ptr] += 6;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr++;
					memory[ptr] += 2;
					ptr--;
				}
				ptr++;
				putchar(memory[ptr]);
				memory[ptr]++;
				while(memory[ptr]) {
					memory[ptr] -= 3;
					ptr++;
					memory[ptr]++;
					ptr--;
				}
				ptr++;
				putchar(memory[ptr]);
				memory[ptr] += 4;
				putchar(memory[ptr]);
				memory[ptr] += 4;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr++;
					memory[ptr] += 3;
					ptr--;
				}
				ptr++;
				putchar(memory[ptr]);
				memory[ptr] -= 2;
				while(memory[ptr]) {
					memory[ptr] -= 3;
					ptr++;
					memory[ptr]++;
					ptr--;
				}
				ptr++;
				putchar(memory[ptr]);
				while(memory[ptr]) {
					memory[ptr] -= 3;
					ptr++;
					memory[ptr]++;
					ptr--;
				}
				ptr++;
				memory[ptr]--;
				putchar(memory[ptr]);
				memory[ptr]++;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr--;
					memory[ptr]++;
				}
				memory[ptr]--;
				ptr--;
				memory[ptr] = 0;
				ptr += 4;
			}
			ptr--;
			memory[ptr]++;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr--;
				memory[ptr]++;
			}
			memory[ptr]--;
			ptr--;
			while(memory[ptr]) {
				ptr += 2;
				memory[ptr]--;
				ptr += 6;
				memory[ptr]++;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr -= 4;
					memory[ptr] = 0;
					ptr -= 2;
					memory[ptr] = 0;
					ptr += 4;
					memory[ptr]--;
					while(memory[ptr]) {
						ptr += 2;
						memory[ptr] = 0;
						memory[ptr]++;
						ptr -= 2;
						memory[ptr]++;
						ptr--;
						memory[ptr] = 0;
						ptr--;
						memory[ptr] = 0;
						ptr--;
						memory[ptr] = 0;
						ptr--;
						memory[ptr] = 0;
						memory[ptr]--;
						while(memory[ptr]) {
							memory[ptr] -= 5;
							ptr++;
							memory[ptr]++;
							ptr--;
						}
						ptr++;
						memory[ptr] -= 3;
						ptr--;
						memory[ptr] = getchar();
						ptr++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]--;
							ptr++;
						}
						ptr--;
						while(memory[ptr]) {
							ptr += 2;
							memory[ptr]++;
							ptr++;
							memory[ptr]++;
							ptr -= 3;
							memory[ptr]--;
						}
						ptr += 2;
						while(memory[ptr]) {
							ptr -= 2;
							memory[ptr]++;
							ptr += 2;
							memory[ptr]--;
						}
						memory[ptr] += 9;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]--;
							while(memory[ptr]) {
								ptr -= 2;
							}
							ptr++;
						}
						ptr += 2;
						memory[ptr]--;
					}
					ptr -= 4;
					memory[ptr] = 0;
					ptr += 4;
					memory[ptr] = 0;
					memory[ptr]++;
					ptr -= 6;
					while(memory[ptr]) {
						ptr += 2;
						memory[ptr]++;
						ptr++;
						memory[ptr]++;
						ptr -= 3;
						memory[ptr]--;
					}
					ptr += 2;
					while(memory[ptr]) {
						ptr -= 2;
						memory[ptr]++;
						ptr += 2;
						memory[ptr]--;
					}
					ptr += 2;
				}
				ptr += 2;
				memory[ptr]--;
				ptr -= 3;
				memory[ptr] = 0;
				ptr -= 2;
				while(memory[ptr]) {
					ptr--;
					memory[ptr]--;
					ptr++;
					memory[ptr]--;
				}
				ptr--;
				memory[ptr]--;
				while(memory[ptr]) {
					memory[ptr]--;
					while(memory[ptr]) {
						memory[ptr]--;
						while(memory[ptr]) {
							memory[ptr]--;
							while(memory[ptr]) {
								memory[ptr]--;
								while(memory[ptr]) {
									memory[ptr]--;
									while(memory[ptr]) {
										memory[ptr]--;
										while(memory[ptr]) {
											memory[ptr]--;
											while(memory[ptr]) {
												memory[ptr]--;
												ptr += 3;
											}
											ptr += 3;
										}
										ptr += 3;
									}
									ptr += 3;
								}
								ptr += 3;
							}
							ptr += 3;
						}
						ptr += 3;
					}
					ptr += 3;
				}
			}
			ptr += 43;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr++;
				memory[ptr] += 2;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr--;
					memory[ptr]++;
				}
				memory[ptr]--;
				ptr += 5;
				while(memory[ptr]) {
					ptr += 3;
					while(memory[ptr]) {
						ptr += 3;
						while(memory[ptr]) {
							memory[ptr]++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr -= 9;
							memory[ptr] = 0;
							memory[ptr] += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr++;
						}
					}
				}
				memory[ptr]++;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr--;
					memory[ptr]++;
				}
				memory[ptr]--;
				ptr += 14;
				while(memory[ptr]) {
					ptr += 3;
					while(memory[ptr]) {
						ptr += 3;
						while(memory[ptr]) {
							memory[ptr]++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr -= 9;
							memory[ptr] = 0;
							memory[ptr] += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr++;
						}
					}
				}
				memory[ptr]++;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr--;
					memory[ptr]++;
				}
				memory[ptr]--;
				ptr += 23;
				while(memory[ptr]) {
					ptr += 3;
					while(memory[ptr]) {
						ptr += 3;
						while(memory[ptr]) {
							memory[ptr]++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr -= 9;
							memory[ptr] = 0;
							memory[ptr] += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr++;
						}
					}
				}
				memory[ptr]++;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr--;
					memory[ptr]++;
				}
				memory[ptr]--;
				ptr += 5;
				while(memory[ptr]) {
					ptr += 9;
					while(memory[ptr]) {
						ptr += 9;
						while(memory[ptr]) {
							memory[ptr]++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr -= 9;
							memory[ptr] = 0;
							memory[ptr] += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr++;
						}
					}
				}
				memory[ptr]++;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr--;
					memory[ptr]++;
				}
				memory[ptr]--;
				ptr += 8;
				while(memory[ptr]) {
					ptr += 9;
					while(memory[ptr]) {
						ptr += 9;
						while(memory[ptr]) {
							memory[ptr]++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr -= 9;
							memory[ptr] = 0;
							memory[ptr] += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr++;
						}
					}
				}
				memory[ptr]++;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr--;
					memory[ptr]++;
				}
				memory[ptr]--;
				ptr += 11;
				while(memory[ptr]) {
					ptr += 9;
					while(memory[ptr]) {
						ptr += 9;
						while(memory[ptr]) {
							memory[ptr]++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr -= 9;
							memory[ptr] = 0;
							memory[ptr] += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr++;
						}
					}
				}
				memory[ptr]++;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr--;
					memory[ptr]++;
				}
				memory[ptr]--;
				ptr += 5;
				while(memory[ptr]) {
					ptr += 12;
					while(memory[ptr]) {
						ptr += 12;
						while(memory[ptr]) {
							memory[ptr]++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr -= 9;
							memory[ptr] = 0;
							memory[ptr] += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr++;
						}
					}
				}
				memory[ptr]++;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr--;
					memory[ptr]++;
				}
				memory[ptr]--;
				ptr += 11;
				while(memory[ptr]) {
					ptr += 6;
					while(memory[ptr]) {
						ptr += 6;
						while(memory[ptr]) {
							memory[ptr]++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr -= 9;
							memory[ptr] = 0;
							memory[ptr] += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr++;
						}
					}
				}
				memory[ptr]++;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr--;
					memory[ptr]++;
				}
				memory[ptr]--;
				ptr -= 9;
				memory[ptr]--;
				while(memory[ptr]) {
					memory[ptr] += 2;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr++;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr -= 10;
					while(memory[ptr]) {
						memory[ptr]--;
					}
					memory[ptr] += 2;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr++;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 4;
					while(memory[ptr]) {
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr -= 10;
						memory[ptr] = 0;
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr++;
					}
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 7;
					while(memory[ptr]) {
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr -= 10;
						memory[ptr] = 0;
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr++;
					}
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 10;
					while(memory[ptr]) {
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr -= 10;
						memory[ptr] = 0;
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr++;
					}
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 13;
					while(memory[ptr]) {
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr -= 10;
						memory[ptr] = 0;
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr++;
					}
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 16;
					while(memory[ptr]) {
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr -= 10;
						memory[ptr] = 0;
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr++;
					}
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 19;
					while(memory[ptr]) {
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr -= 10;
						memory[ptr] = 0;
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr++;
					}
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 22;
					while(memory[ptr]) {
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr -= 10;
						memory[ptr] = 0;
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr++;
					}
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 25;
					while(memory[ptr]) {
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr -= 10;
						memory[ptr] = 0;
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr++;
					}
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 28;
					while(memory[ptr]) {
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr -= 10;
						memory[ptr] = 0;
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr++;
					}
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr -= 2;
					memory[ptr] = 0;
					ptr++;
					memory[ptr] = 0;
					memory[ptr]++;
					ptr += 6;
					while(memory[ptr]) {
						ptr += 3;
						while(memory[ptr]) {
							ptr += 2;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 4;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 5;
					while(memory[ptr]) {
						ptr += 2;
						while(memory[ptr]) {
							ptr += 4;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 3;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 4;
					while(memory[ptr]) {
						ptr += 4;
						while(memory[ptr]) {
							ptr += 3;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 2;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 14;
					while(memory[ptr]) {
						ptr += 3;
						while(memory[ptr]) {
							ptr += 2;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 7;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 14;
					while(memory[ptr]) {
						ptr += 2;
						while(memory[ptr]) {
							ptr += 4;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 6;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 13;
					while(memory[ptr]) {
						ptr += 4;
						while(memory[ptr]) {
							ptr += 3;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 5;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 23;
					while(memory[ptr]) {
						ptr += 3;
						while(memory[ptr]) {
							ptr += 2;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 10;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 23;
					while(memory[ptr]) {
						ptr += 2;
						while(memory[ptr]) {
							ptr += 4;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 9;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 22;
					while(memory[ptr]) {
						ptr += 4;
						while(memory[ptr]) {
							ptr += 3;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 8;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 5;
					while(memory[ptr]) {
						ptr += 9;
						while(memory[ptr]) {
							ptr += 8;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 8;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 5;
					while(memory[ptr]) {
						ptr += 8;
						while(memory[ptr]) {
							ptr += 10;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 5;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 4;
					while(memory[ptr]) {
						ptr += 10;
						while(memory[ptr]) {
							ptr += 9;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 2;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 8;
					while(memory[ptr]) {
						ptr += 9;
						while(memory[ptr]) {
							ptr += 8;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 9;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 8;
					while(memory[ptr]) {
						ptr += 8;
						while(memory[ptr]) {
							ptr += 10;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 6;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 7;
					while(memory[ptr]) {
						ptr += 10;
						while(memory[ptr]) {
							ptr += 9;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 3;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 11;
					while(memory[ptr]) {
						ptr += 9;
						while(memory[ptr]) {
							ptr += 8;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 10;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 11;
					while(memory[ptr]) {
						ptr += 8;
						while(memory[ptr]) {
							ptr += 10;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 7;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 10;
					while(memory[ptr]) {
						ptr += 10;
						while(memory[ptr]) {
							ptr += 9;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 4;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 5;
					while(memory[ptr]) {
						ptr += 12;
						while(memory[ptr]) {
							ptr += 11;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 10;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 4;
					while(memory[ptr]) {
						ptr += 13;
						while(memory[ptr]) {
							ptr += 12;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 2;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 11;
					while(memory[ptr]) {
						ptr += 6;
						while(memory[ptr]) {
							ptr += 5;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 8;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 10;
					while(memory[ptr]) {
						ptr += 7;
						while(memory[ptr]) {
							ptr += 6;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 4;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 6;
					while(memory[ptr]) {
						ptr += 3;
						while(memory[ptr]) {
							ptr++;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 4;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 6;
					while(memory[ptr]) {
						ptr++;
						while(memory[ptr]) {
							ptr += 5;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 3;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 4;
					while(memory[ptr]) {
						ptr += 5;
						while(memory[ptr]) {
							ptr += 3;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 2;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 15;
					while(memory[ptr]) {
						ptr += 3;
						while(memory[ptr]) {
							ptr++;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 7;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 15;
					while(memory[ptr]) {
						ptr++;
						while(memory[ptr]) {
							ptr += 5;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 6;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 13;
					while(memory[ptr]) {
						ptr += 5;
						while(memory[ptr]) {
							ptr += 3;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 5;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 24;
					while(memory[ptr]) {
						ptr += 3;
						while(memory[ptr]) {
							ptr++;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 10;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 24;
					while(memory[ptr]) {
						ptr++;
						while(memory[ptr]) {
							ptr += 5;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 9;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 22;
					while(memory[ptr]) {
						ptr += 5;
						while(memory[ptr]) {
							ptr += 3;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 8;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 6;
					while(memory[ptr]) {
						ptr += 9;
						while(memory[ptr]) {
							ptr += 7;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 8;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 6;
					while(memory[ptr]) {
						ptr += 7;
						while(memory[ptr]) {
							ptr += 11;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 5;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 4;
					while(memory[ptr]) {
						ptr += 11;
						while(memory[ptr]) {
							ptr += 9;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 2;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 9;
					while(memory[ptr]) {
						ptr += 9;
						while(memory[ptr]) {
							ptr += 7;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 9;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 9;
					while(memory[ptr]) {
						ptr += 7;
						while(memory[ptr]) {
							ptr += 11;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								while(memory[ptr]) {
									memory[ptr]--;
								}
								memory[ptr] += 6;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 7;
					while(memory[ptr]) {
						ptr += 11;
						while(memory[ptr]) {
							ptr += 9;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 3;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 12;
					while(memory[ptr]) {
						ptr += 9;
						while(memory[ptr]) {
							ptr += 7;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 10;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 12;
					while(memory[ptr]) {
						ptr += 7;
						while(memory[ptr]) {
							ptr += 11;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 7;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 10;
					while(memory[ptr]) {
						ptr += 11;
						while(memory[ptr]) {
							ptr += 9;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 4;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 6;
					while(memory[ptr]) {
						ptr += 12;
						while(memory[ptr]) {
							ptr += 10;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 10;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 4;
					while(memory[ptr]) {
						ptr += 14;
						while(memory[ptr]) {
							ptr += 12;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 2;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 12;
					while(memory[ptr]) {
						ptr += 6;
						while(memory[ptr]) {
							ptr += 4;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 8;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 10;
					while(memory[ptr]) {
						ptr += 8;
						while(memory[ptr]) {
							ptr += 6;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr--;
								memory[ptr] = 0;
								ptr--;
								memory[ptr] = 0;
								memory[ptr] += 4;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					ptr++;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr--;
					while(memory[ptr]) {
						ptr += 2;
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr += 28;
						while(memory[ptr]) {
							memory[ptr]++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr--;
							memory[ptr] = 0;
							ptr--;
							memory[ptr] = 0;
							memory[ptr] += 10;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr++;
						}
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr += 22;
						while(memory[ptr]) {
							memory[ptr]++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr--;
							memory[ptr] = 0;
							ptr--;
							memory[ptr] = 0;
							memory[ptr] += 8;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr++;
						}
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr += 10;
						while(memory[ptr]) {
							memory[ptr]++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr--;
							memory[ptr] = 0;
							ptr--;
							memory[ptr] = 0;
							memory[ptr] += 4;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr++;
						}
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr += 4;
						while(memory[ptr]) {
							memory[ptr]++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr--;
							memory[ptr] = 0;
							ptr--;
							memory[ptr] = 0;
							memory[ptr] += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr++;
						}
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr += 25;
						while(memory[ptr]) {
							memory[ptr]++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr--;
							memory[ptr] = 0;
							ptr--;
							memory[ptr] = 0;
							memory[ptr] += 9;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr++;
						}
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr += 19;
						while(memory[ptr]) {
							memory[ptr]++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr--;
							memory[ptr] = 0;
							ptr--;
							memory[ptr] = 0;
							memory[ptr] += 7;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr++;
						}
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr += 13;
						while(memory[ptr]) {
							memory[ptr]++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr--;
							memory[ptr] = 0;
							ptr--;
							memory[ptr] = 0;
							memory[ptr] += 5;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr++;
						}
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr += 7;
						while(memory[ptr]) {
							memory[ptr]++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr--;
							memory[ptr] = 0;
							ptr--;
							memory[ptr] = 0;
							memory[ptr] += 3;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr++;
						}
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr += 16;
						while(memory[ptr]) {
							memory[ptr]++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr--;
							memory[ptr] = 0;
							ptr--;
							memory[ptr] = 0;
							memory[ptr] += 6;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr++;
						}
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr++;
					}
					ptr += 2;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr -= 4;
					while(memory[ptr]) {
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr++;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr += 17;
						while(memory[ptr]) {
							memory[ptr]++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr--;
							memory[ptr] = 0;
							ptr--;
							memory[ptr] = 0;
							memory[ptr] += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr++;
						}
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr++;
					}
					ptr += 4;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr -= 2;
					while(memory[ptr]) {
						ptr += 3;
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr--;
						memory[ptr] = 0;
						ptr--;
						while(memory[ptr]) {
							memory[ptr]++;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr--;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr++;
							memory[ptr] += 2;
							while(memory[ptr]) {
								memory[ptr]--;
								ptr++;
								memory[ptr]++;
							}
							memory[ptr]--;
							ptr -= 2;
							memory[ptr]--;
						}
						memory[ptr]++;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr++;
						memory[ptr]--;
						while(memory[ptr]) {
							memory[ptr]--;
							while(memory[ptr]) {
								memory[ptr]--;
								while(memory[ptr]) {
									memory[ptr]--;
									while(memory[ptr]) {
										memory[ptr]--;
										while(memory[ptr]) {
											memory[ptr]--;
											while(memory[ptr]) {
												memory[ptr]--;
												while(memory[ptr]) {
													memory[ptr]--;
													while(memory[ptr]) {
														memory[ptr]--;
														ptr += 3;
													}
													ptr += 3;
												}
												ptr += 3;
											}
											ptr += 3;
										}
										ptr += 3;
									}
									ptr += 3;
								}
								ptr += 3;
							}
							ptr += 3;
						}
						ptr += 43;
						memory[ptr]--;
						ptr += 2;
						memory[ptr] += 2;
						while(memory[ptr]) {
							memory[ptr]--;
							ptr--;
							memory[ptr]++;
						}
						memory[ptr]--;
						ptr++;
					}
					ptr += 4;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr -= 2;
					memory[ptr] = 0;
					ptr += 3;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr -= 4;
					memory[ptr] = 0;
					ptr += 5;
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 6;
					while(memory[ptr]) {
						ptr += 3;
						while(memory[ptr]) {
							ptr += 3;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr -= 11;
								memory[ptr] = 0;
								memory[ptr] += 2;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 15;
					while(memory[ptr]) {
						ptr += 3;
						while(memory[ptr]) {
							ptr += 3;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr -= 11;
								memory[ptr] = 0;
								memory[ptr] += 2;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 24;
					while(memory[ptr]) {
						ptr += 3;
						while(memory[ptr]) {
							ptr += 3;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr -= 11;
								memory[ptr] = 0;
								memory[ptr] += 2;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 6;
					while(memory[ptr]) {
						ptr += 9;
						while(memory[ptr]) {
							ptr += 9;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr -= 11;
								memory[ptr] = 0;
								memory[ptr] += 2;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 9;
					while(memory[ptr]) {
						ptr += 9;
						while(memory[ptr]) {
							ptr += 9;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr -= 11;
								memory[ptr] = 0;
								memory[ptr] += 2;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 12;
					while(memory[ptr]) {
						ptr += 9;
						while(memory[ptr]) {
							ptr += 9;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr -= 11;
								memory[ptr] = 0;
								memory[ptr] += 2;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 6;
					while(memory[ptr]) {
						ptr += 12;
						while(memory[ptr]) {
							ptr += 12;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr -= 11;
								memory[ptr] = 0;
								memory[ptr] += 2;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr += 12;
					while(memory[ptr]) {
						ptr += 6;
						while(memory[ptr]) {
							ptr += 6;
							while(memory[ptr]) {
								memory[ptr]++;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr--;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr -= 11;
								memory[ptr] = 0;
								memory[ptr] += 2;
								while(memory[ptr]) {
									memory[ptr]--;
									ptr++;
									memory[ptr]++;
								}
								memory[ptr]--;
								ptr++;
							}
						}
					}
					memory[ptr]++;
					while(memory[ptr]) {
						memory[ptr]--;
						ptr--;
						memory[ptr]++;
					}
					memory[ptr]--;
					ptr--;
					memory[ptr] = 0;
				}
				memory[ptr] += 2;
				while(memory[ptr]) {
					memory[ptr]--;
					ptr++;
					memory[ptr]++;
				}
				memory[ptr]--;
				ptr++;
			}
			memory[ptr]++;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr--;
				memory[ptr]++;
			}
			memory[ptr]--;
			ptr--;
			memory[ptr]++;
			while(memory[ptr]) {
				memory[ptr]--;
				ptr--;
				memory[ptr]++;
			}
			memory[ptr]--;
			ptr--;
		}
		ptr += 2;
		memory[ptr]++;
		while(memory[ptr]) {
			memory[ptr]--;
			ptr++;
			memory[ptr]++;
		}
		memory[ptr]--;
		ptr += 31;
		memory[ptr]++;
		while(memory[ptr]) {
			memory[ptr]--;
			memory[ptr] = 0;
			ptr--;
			memory[ptr]++;
		}
		memory[ptr]--;
		ptr--;
		memory[ptr]++;
		while(memory[ptr]) {
			memory[ptr]--;
			memory[ptr] = 0;
			ptr--;
			memory[ptr]++;
		}
		memory[ptr]--;
		ptr--;
		memory[ptr]++;
		ptr++;
	}

	return 0;
}
