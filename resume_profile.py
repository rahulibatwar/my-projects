class ResumeProfile:
    def __init__(self, name, role):
        self.name = name
        self.role = role
        self.skills = []
        self.experience = {}

    def add_skill(self, skill):
        self.skills.append(skill)

    def add_experience(self, company, duration):
        self.experience[company] = duration

    def display_profile(self):
        print(f"--- Professional Profile: {self.name} ---")
        print(f"Current Role: {self.role}")
        print(f"Core Skills: {', '.join(self.skills)}")
        print("Work History:")
        for company, time in self.experience.items():
            print(f" - {company}: {time}")

# Creating Rahul's Technical Profile Object
rahul_profile = ResumeProfile(name="Rahul Ibatwar", role="Maintenance Executive")

# Adding Core Technical Skills
rahul_profile.add_skill("Industrial Automation")
rahul_profile.add_skill("Electrical Maintenance")
rahul_profile.add_skill("CCTV Networking")
rahul_profile.add_skill("Python & C++")

# Adding Verified Work Experience
rahul_profile.add_experience("Midea India Pvt Ltd", "1 Year")
rahul_profile.add_experience("Trueview India", "1 Year")
rahul_profile.add_experience("Endurance Technologies Ltd", "4 Months")
rahul_profile.add_experience("Millora Corporate Services", "Present")

# Execute and Display Output
rahul_profile.display_profile()