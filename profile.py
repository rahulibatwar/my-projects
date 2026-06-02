# ==============================================================================
# STUDENT PROFILE & ROADMAP: RAHUL GANGADHAR IBATWAR
# Goal: Software Architect @ Google
# ==============================================================================

import time

def show_profile():
    print("=" * 60)
    print("         RAHUL GANGADHAR IBATWAR - PROFESSIONAL PROFILE         ")
    print("=" * 60)
    print(f"• Current Education : CSE Diploma (2nd Year, 3rd Semester)")
    print(f"• Current Target    : GCC-TBC Typing Exam (June 2026)")
    print(f"• Target Speed      : 30+ WPM with 100% Accuracy")
    print(f"• Core Languages    : C++, Python, Java")
    print(f"• Ultimate Dream    : Software Architect at Google 🚀")
    print("=" * 60)
    print()

def show_roadmap():
    print("=" * 60)
    print("             MY STEP-BY-STEP ROADMAP TO GOOGLE              ")
    print("=" * 60)
    
    phases = [
        ("Phase 1: Diploma (Current)", "Focus on C++, Python, Data Structures base & keep Typing Practice daily."),
        ("Phase 2: B.Tech Degree", "Deep dive into Data Structures & Algorithms (DSA), solve LeetCode problems daily."),
        ("Phase 3: System Design", "Learn how massive apps like YouTube, Maps, and Google Search scale globally."),
        ("Phase 4: Google FAANG", "Build strong GitHub portfolio, do internships, get referrals, and crack the interview!")
    ]
    
    for phase, detail in phases:
        print(f"▶ {phase}")
        print(f"  Details: {detail}")
        print("-" * 60)

if __name__ == "__main__":
    show_profile()
    time.sleep(1)  # 1 second pause visual effect ke liye
    show_roadmap()