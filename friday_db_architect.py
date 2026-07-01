import sqlite3

class EnterpriseDatabaseSystem:
    """Simulating an Enterprise Relational Database Schema using SQLite"""
    def __init__(self):
        # Creating an in-memory SQL database for lightning-fast testing
        self.conn = sqlite3.connect(":memory:")
        self.cursor = self.conn.cursor()
        self._build_schema()

    def _build_schema(self):
        """Architecting the Relational Schema (Tables & Constraints)"""
        # 1. Create Roles Master Table
        self.cursor.execute("""
            CREATE TABLE Roles (
                role_id INTEGER PRIMARY KEY AUTOINCREMENT,
                role_name TEXT NOT NULL UNIQUE,
                access_level INTEGER NOT NULL
            )
        """)

        # 2. Create Users Table with Foreign Key mapping to Roles
        self.cursor.execute("""
            CREATE TABLE Users (
                user_id INTEGER PRIMARY KEY AUTOINCREMENT,
                username TEXT NOT NULL UNIQUE,
                email TEXT NOT NULL,
                role_id INTEGER,
                FOREIGN KEY (role_id) REFERENCES Roles(role_id)
            )
        """)
        self.conn.commit()
        print("🧱 [Database] Relational Schema Built Successfully with Foreign Keys.")

    def seed_initial_data(self):
        """Seeding infrastructure data into tables"""
        # Inserting Roles
        roles_data = [('System Admin', 100), ('Software Architect', 90), ('Standard User', 10)]
        self.cursor.executemany("INSERT INTO Roles (role_name, access_level) VALUES (?, ?)", roles_data)

        # Inserting Users linked with role_ids
        users_data = [
            ('Rahul_Architect', 'rahul@google.com', 2),  # Linked to Software Architect
            ('System_Root', 'root@server.com', 1),       # Linked to System Admin
            ('Guest_User', 'guest@test.com', 3)          # Linked to Standard User
        ]
        self.cursor.executemany("INSERT INTO Users (username, email, role_id) VALUES (?, ?, ?)", users_data)
        self.conn.commit()
        print("💾 [Database] Initial master records injected safely.")

    def fetch_user_authorization_details(self):
        """Executing an Optimized SQL JOIN Query for access control mapping"""
        print("\n🔍 [Query] Fetching Consolidated Security Tokens (SQL INNER JOIN)...")
        
        # High-performance Join logic
        query = """
            SELECT Users.user_id, Users.username, Roles.role_name, Roles.access_level 
            FROM Users 
            INNER JOIN Roles ON Users.role_id = Roles.role_id
        """
        self.cursor.execute(query)
        records = self.cursor.fetchall()

        print("-" * 65)
        print(f"{'UID':<5} | {'Username':<18} | {'Assigned Role':<20} | {'Access Level'}")
        print("-" * 65)
        for row in records:
            print(f"{row[0]:<5} | {row[1]:<18} | {row[2]:<20} | {row[3]}")
        print("-" * 65)

    def close_connection(self):
        self.conn.close()

def main():
    print("=" * 65)
    print("      AI Architecture: Relational Database Layer & SQL Joins      ")
    print("=" * 65)

    # Initialize and execute the architecture layer
    db_system = EnterpriseDatabaseSystem()
    db_system.seed_initial_data()
    db_system.fetch_user_authorization_details()
    db_system.close_connection()

if __name__ == "__main__":
    main()