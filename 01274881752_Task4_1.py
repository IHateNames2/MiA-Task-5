class Villain:
    def __init__(self, name, weapons, shields):
        self.name = name
        self.weapons = weapons
        self.shields = shields
        self.health = 100
        self.energy = 500
        self.shield = None

    def attack(self, opponent, weapon):
        if opponent.shield:
            damage = weapon.damage * (1 - opponent.shield.reduction)
            opponent.health -= damage
            print(f"{self.name} attacks {opponent.name} with {weapon.name} for {damage} damage")
        else:
            opponent.health -= weapon.damage
            print(f"{self.name} attacks {opponent.name} with {weapon.name} for {weapon.damage} damage")
        self.energy -= weapon.energy_cost

    def defend(self, shield):
        self.shield = shield
        print(f"{self.name} defends with {shield.name}")

    def is_alive(self):
        return self.health > 0


class Weapon:
    def __init__(self, name, damage, energy_cost):
        self.name = name
        self.damage = damage
        self.energy_cost = energy_cost


class Shield:
    def __init__(self, name, reduction):
        self.name = name
        self.reduction = reduction


class Game:
    def __init__(self, villain1, villain2):
        self.villain1 = villain1
        self.villain2 = villain2

    def play_round(self, villain1_weapon, villain2_weapon, villain1_shield=None, villain2_shield=None):
        if villain1_shield:
            self.villain1.defend(villain1_shield)
        if villain2_shield:
            self.villain2.defend(villain2_shield)
        self.villain1.attack(self.villain2, villain1_weapon)
        if self.villain2.is_alive():
            self.villain2.attack(self.villain1, villain2_weapon)

    def choose_from_menu(self, items):
        for i, item in enumerate(items):
            print(f"{i + 1}. {item.name}")
        choice = int(input())
        return items[choice - 1]

    def play_game(self):
        round_number = 1
        while self.villain1.is_alive() and self.villain2.is_alive():
            print(f"Round {round_number}")
            # User chooses weapons and shields for both villains here
            print(f"Choose a weapon for {self.villain1.name}: ")
            weapon1 = self.choose_from_menu(self.villain1.weapons)
            print(f"Choose a shield for {self.villain1.name}: ")
            shield1 = self.choose_from_menu(self.villain1.shields)
            print(f"Choose a weapon for {self.villain2.name}: ")
            weapon2 = self.choose_from_menu(self.villain2.weapons)
            print(f"Choose a shield for {self.villain2.name}: ")
            shield2 = self.choose_from_menu(self.villain2.shields)
            self.play_round(weapon1, weapon2, shield1, shield2)
            round_number += 1

# Gru's weapons
gru_weapons = [
    Weapon("Freeze Gun", 11, 50),
    Weapon("Electric Prod", 18, 88),
    Weapon("Mega Magnet", 10, 92),
    Weapon("Kalman Missile", 20, 120)
]

# Gru's shields
gru_shields = [
    Shield("Energy-Projected Barrier Gun", 0.4),
    Shield("Selective Permeability", 0.9)
]

# Vector's weapons
vector_weapons = [
    Weapon("Laser Blaster", 8, 40),
    Weapon("Plasma Grenade", 13, 56),
    Weapon("Sonic Resonance Cannon", 22, 100)
]

# Vector's shields
vector_shields = [
    Shield("Energy Net Trap", 0.32),
    Shield("Quantum Deflector", 0.8)
]

# Example usage:
gru = Villain("Gru", gru_weapons, gru_shields)
vector = Villain("Vector", vector_weapons, vector_shields)
game = Game(gru, vector)
game.play_game()
